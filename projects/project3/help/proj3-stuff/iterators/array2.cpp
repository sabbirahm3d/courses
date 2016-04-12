#include <iostream>

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int *i = a;
    int *end = a + 8;

    while (i != end)
    {
        std::cout << *i << std::endl;
        i++;
    }

    return 0;
}
