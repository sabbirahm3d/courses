#include <iostream>

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
    PrintNumber()(42);

    PrintNumber printer;
    printer(13);

    for (int i = 0; i < 20; i++)
    {
        printer(i);
    }

    return 0;
}
