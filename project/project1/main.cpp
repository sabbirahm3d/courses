#include "main.h"


std::vector<std::vector<mpz_class>> parse_file(const char *file_name) {

    std::ifstream file(file_name);
    std::string line;
    std::vector<std::vector<mpz_class>> complex_nums;

    while (std::getline(file, line)) {
        complex_nums.push_back(line_to_mpz(line));
    }

    return complex_nums;

}


std::vector<mpz_class> cmul3(const std::vector<mpz_class> z1, const std::vector<mpz_class> z2) {

    mpz_class r, s;
    std::vector<mpz_class> pair(2);

    r = z1[0] * z2[0];  // x1 * x2
    s = z1[1] * z2[1];  // y1 * y2

    pair[0] = r - s;
    pair[1] = (z1[0] + z1[1]) * (z2[0] + z2[1]) - r - s;

    return pair;

}


// (x1 * x2 − y1 * y2) + i(x1 * y2 + y1 * x2)
std::vector<mpz_class> cmul4(const std::vector<mpz_class> z1, const std::vector<mpz_class> z2) {

    std::vector<mpz_class> pair(2);

    pair[0] = z1[0] * z2[0] - z1[1] * z2[1];  // x1 * x2 − y1 * y2
    pair[1] = z1[0] * z2[1] + z1[1] * z2[0];  // x1 * y2 + y1 * x2

    return pair;

}


// ---------------------------------- OUR IMPLEMENTATION ----------------------------------
std::vector<mpz_class> line_to_mpz(const std::string &str) {

    std::string next;
    std::vector<mpz_class> pair(2);
    size_t str_size;

    // for each char
    for (char it : str) {
        // if the char == ','
        if (it == ',') {
            // If we have some characters accumulated
            if (!next.empty()) {
                str_size = next.size();
                pair[0] = mpz_class(next.substr(1, str_size).c_str(), 10);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += it;
        }
    }

    if (!next.empty()) {
        str_size = next.size();
        pair[1] = mpz_class(next.substr(0, str_size - 1).c_str(), 10);
    }

//    destructors for mpz objects - works fine here, but may need to be called later instead
//    mpz_clear(pair[0]);
//    mpz_clear(pair[1]);

    return pair;

}


std::vector<mpz_class> cmul3_list(std::vector<std::vector<mpz_class>> complex_array,
                                  const size_t first, const size_t last) {

    if (first == last) {
        return complex_array[first];
    }

    size_t mid = (first + last) / 2;

    return cmul3(
            cmul3_list(complex_array, first, mid),
            cmul3_list(complex_array, mid + 1, last)
    );

}


std::vector<mpz_class> cmul4_list(std::vector<std::vector<mpz_class>> complex_array,
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


int main(int argc, char *argv[]) {

    if (argc == 2) {

        std::vector<std::vector<mpz_class>> complex_nums;
        std::vector<mpz_class> prod;
        clock_t t0, t;  // used for timing functions

        complex_nums = parse_file(argv[1]);

        t0 = clock();
        prod = cmul4_list(complex_nums, 0, complex_nums.size() - 1);
        t = clock() - t0;
        gmp_printf("%Zd + i%Zd\n", prod[0], prod[1]);
        fprintf(stdout, "*** CMUL4 List ***\n");
        fprintf(stdout, "time: %f\n", ((double) t) / CLOCKS_PER_SEC);

        t0 = clock();
        prod = cmul3_list(complex_nums, 0, complex_nums.size() - 1);
        t = clock() - t0;
        gmp_printf("%Zd + i%Zd\n", prod[0], prod[1]);
        fprintf(stdout, "*** CMUL3 List ***\n");
        fprintf(stdout, "time: %f\n", ((double) t) / CLOCKS_PER_SEC);

        return EXIT_SUCCESS;

    } else {

        std::cout << "Please provide a valid file name" << std::endl;
        return EXIT_FAILURE;

    }

}
