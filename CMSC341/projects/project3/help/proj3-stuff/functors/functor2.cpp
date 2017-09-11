#include <iostream>
#include <algorithm>
#include <vector>

class PrintNumber
{
public:
    void operator()(int n) const
    {
        std::cout << n << std::endl;
    }
};

int main()
{
    std::vector<int> v;
    PrintNumber printer;

    for (int i = 0; i < 20; i++)
    {
        v.push_back(i);
    }

    std::for_each(v.begin(), v.end(), printer);

    return 0;
}
