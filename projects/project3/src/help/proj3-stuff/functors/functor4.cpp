#include <iostream>
#include <string>

class NoLessThan
{

};

class Fraction
{
private:
    int _n;
    int _d;

public:
    Fraction(int n, int d) : _n(n), _d(d) {}

    bool operator<(const Fraction &other) const
    {
        return ((double) _n / (double) _d) <
            ((double) other._n / (double) other._d);
    }
};

template <typename T>
class Compare
{
public:
    bool operator()(T a, T b) const
    {
        return a < b;
    }
};

int main()
{
    Compare<int> int_compare;
    Compare<std::string> string_compare;
    Compare<NoLessThan> doesnt_work;
    Compare<Fraction> fraction_compare;

    std::cout << "3 < 5: " << int_compare(3, 5) << '\n';
    std::cout << "5 < 3: " << int_compare(5, 3) << '\n';
    std::cout << "3 < 3: " << int_compare(3, 3) << '\n' << std::endl;

    std::cout << "Three < Five: " << string_compare("Three", "Five") << '\n';
    std::cout << "Five < Three: " << string_compare("Five", "Three") << '\n';
    std::cout << "Five < Five: " << string_compare("Five", "Five") << '\n';
    std::cout << std::endl;

    // This doesn't work because the NoLessThan class doesn't
    // overload operator<
    //std::cout << doesnt_work(NoLessThan(), NoLessThan()) << '\n' << std::endl;
    
    Fraction f1(1, 2);
    Fraction f2(2, 7);

    std::cout << "1/2 < 2/7: " << fraction_compare(f1, f2) << '\n';
    std::cout << "2/7 < 1/2: " << fraction_compare(f2, f1) << '\n';
    std::cout << "1/2 < 1/2: " << fraction_compare(f1, f1) << '\n' << std::endl;

    return 0;
}
