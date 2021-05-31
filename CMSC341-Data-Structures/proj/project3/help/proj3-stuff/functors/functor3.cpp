#include <iostream>
#include <algorithm>
#include <vector>

class PrintNumber
{
public:
    void operator()(int n)
    {
        std::cout << n << std::endl;
    }
};

class Scale
{
private:
    int _s;

public:
    Scale(int s) : _s(s) {}

    int operator()(int n) const
    {
        return _s * n;
    }
};

int main()
{
    std::vector<int> v;
    PrintNumber printer;
    Scale three(3);

    for (int i = 0; i < 20; i++)
    {
        v.push_back(i);
    }

    std::for_each(v.begin(), v.end(), printer);
    std::cout << std::endl;

    std::transform(v.begin(), v.end(), v.begin(), three);
    std::for_each(v.begin(), v.end(), printer);

    return 0;
}
