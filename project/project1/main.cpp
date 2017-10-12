/*
Sabbir Ahmed, Zafar Mamarakhimov
10/12/2017

main.cpp
Main driver file for Project 1: Divide and Conquer. This script takes in the
path to a valid data file containing lists of complex numbers, and multiplies
them to compute the final product. The computation of the same input is done
twice using two different methods to clarify a crossover range between them.

The file utilizes GMP, and its C++ wrapper, GMPXX. The wrapper handles
initialization of the mpz_t variables, and supports operator overloading
required for the addition and multiplication operators.

To build, a Makefile has been provided:

    make compile

After successful compilation, the Makefile may also be used to run the
executable:

    make run PATH=path/to/file

*/

#include "main.h"


/*
Converts string lines from the file to GMP integer pairs

Inputs:
    - line (const std::string):
        line from file

Outputs:
    - pair (std::vector<mpz_class>):
        pair of MPZ_ints representing the real and imaginary parts of a
        complex number
*/
std::vector<mpz_class> line_to_mpz(const std::string &line) {

    std::string next;
    std::vector<mpz_class> pair(2);
    size_t str_size;

    // splits line using ',' as the delimiter, and assigns each halves to the
    // pair
    for (char it : line) {
        // if the char == ','
        if (it == ',') {
            // if string is accumulated
            if (!next.empty()) {
                str_size = next.size();
                // convert valid string to mpz_class
                pair[0] = mpz_class(next.substr(1, str_size).c_str(), 10);
                next.clear();
            }
        } else {
            // accumulate the next character into the sequence
            next += it;
        }
    }

    // the other half of the string following the delimiter is added to the
    // second index
    if (!next.empty()) {
        str_size = next.size();
        // convert valid string to mpz_class
        pair[1] = mpz_class(next.substr(0, str_size - 1).c_str(), 10);
    }

    return pair;

}


/*
Parses the input file from its path provided via the command line and stores
them in a vector after conversion to MPZ integers

Inputs:
    - file_name (const char*):
        path of the input file

Outputs:
    - complex_nums (std::vector<std::vector<mpz_class>>):
        vector of GMP integer pairs representing the real and imaginary parts
        of complex numbers
*/
std::vector<std::vector<mpz_class>> parse_file(const char *file_name) {

    std::ifstream input_file(file_name);  // input file
    std::string line;
    std::vector<std::vector<mpz_class>> complex_nums;

    if (input_file.is_open()) {  // if file exists and is valid

        // read until EOF
        while (std::getline(input_file, line)) {
            // convert each line to GMP integer pairs and push to the vector
            complex_nums.push_back(line_to_mpz(line));
        }

    }

    return complex_nums;

}


/*
Uses the four-multiplication method to multiply two complex numbers

    (x1 * x2 − y1 * y2) + i(x1 * y2 + y1 * x2)

Inputs:
    - z1, z2 (const std::vector<mpz_class>):
        two GMP integer pairs representing complex numbers

Outputs:
    - pair (std::vector<mpz_class>):
        GMP integer pair representing the complex product

*/
// 
std::vector<mpz_class> cmul4(const std::vector<mpz_class> z1,
                             const std::vector<mpz_class> z2) {

    std::vector<mpz_class> pair(2);

    pair[0] = z1[0] * z2[0] - z1[1] * z2[1];  // x1 * x2 − y1 * y2
    pair[1] = z1[0] * z2[1] + z1[1] * z2[0];  // x1 * y2 + y1 * x2

    return pair;

}


/*
Uses the three-multiplication method to multiply two complex numbers

    ((x1 * x2) - (y1 * y2)) + i((x1 + y1)(x2 + y2) - (x1 * x2) - (y1 * y2))

Inputs:
    - z1, z2 (const std::vector<mpz_class>):
        two GMP integer pairs representing complex numbers

Outputs:
    - pair (std::vector<mpz_class>):
        GMP integer pair representing the complex product

*/
std::vector<mpz_class> cmul3(const std::vector<mpz_class> z1,
                             const std::vector<mpz_class> z2) {

    mpz_class r, s;
    std::vector<mpz_class> pair(2);

    r = z1[0] * z2[0];  // x1 * x2
    s = z1[1] * z2[1];  // y1 * y2

    pair[0] = r - s;
    pair[1] = (z1[0] + z1[1]) * (z2[0] + z2[1]) - r - s;

    return pair;

}


/*
Uses a divide and conquer method to recursively multiply all the elements in
the complex array using the three-multiplication method

Inputs:
    - complex_array (std::vector<mpz_class>):
        vector of GMP integer pairs
    - first, last (const size_t): first and last indices of the subarray

Outputs:
    - cmul3() outputs (std::vector<mpz_class>):
        final complex product
*/
std::vector<mpz_class> cmul3_list(
        std::vector<std::vector<mpz_class>> complex_array,
        const size_t first,
        const size_t last
) {

    if (first == last) {
        return complex_array[first];
    }

    size_t mid = (first + last) / 2;

    return cmul3(
            cmul3_list(complex_array, first, mid),
            cmul3_list(complex_array, mid + 1, last)
    );

}


/*
Uses a divide and conquer method to recursively multiply all the elements in
the complex array using the fours-multiplication method

Inputs:
    - complex_array (std::vector<mpz_class>):
        vector of GMP integer pairs
    - first, last (const size_t): first and last indices of the subarray

Outputs:
    - cmul4() outputs (std::vector<mpz_class>):
        final complex product
*/
std::vector<mpz_class>
cmul4_list(std::vector<std::vector<mpz_class>> complex_array,
           const size_t first, const size_t last) {

    if (first == last) {
        return complex_array[first];
    }

    size_t mid = (first + last) / 2;

    return cmul4(
            cmul4_list(complex_array, first, mid),
            cmul4_list(complex_array, mid + 1, last)
    );

}

/*
Main driver function for the file. Handles the user inputted path to the data
file, and generates the execution times for the different methods
*/
int main(int argc, char *argv[]) {

    // if file path is provided as a command line argument
    if (argc == 2) {

        std::vector<std::vector<mpz_class>> complex_nums;
        clock_t t0, t;  // used for timing functions
        size_t complex_num_size;

        /* final complex product - used for verifying accuracy of the outputs
         commented out to prevent clutter in console for analyzing execution
         times.
         The product can be assigned as the output to any of the complex
         list multipliying functions, i.e.

            prod = cmul4_list(complex_nums, 0, complex_nums.size() - 1);
        */
        // std::vector<mpz_class> prod;

        complex_nums = parse_file(argv[1]);
        complex_num_size = complex_nums.size();

        // if vector was filled with complex integers, i.e. the file was valid
        if (complex_num_size) {

            // four-multiply
            t0 = clock();
            cmul4_list(complex_nums, 0, complex_num_size - 1);
            t = clock() - t0;  // compute the time it took
            fprintf(stdout, "*** CMUL4 List ***\n");
            fprintf(stdout, "time: %f\n", ((double) t) / CLOCKS_PER_SEC);

            // three-multiply
            t0 = clock();
            cmul3_list(complex_nums, 0, complex_num_size - 1);
            t = clock() - t0;  // compute the time it took
            fprintf(stdout, "*** CMUL3 List ***\n");
            fprintf(stdout, "time: %f\n", ((double) t) / CLOCKS_PER_SEC);

            return EXIT_SUCCESS;

        } else {  // if file was invalid or empty

            std::cout << "Please provide a valid file name" << std::endl;
            return EXIT_FAILURE;

        }

    } else {  // if no command line input was provided

        std::cout << "Please provide a file name as the command line input" <<
                  std::endl;
        return EXIT_FAILURE;

    }

}
