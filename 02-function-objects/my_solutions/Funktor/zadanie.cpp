#include <iostream>

struct Funktor
{
    void operator()(int number)
    {
        if (number % 6 == 0)
        {
            std::cout << "Number: " << number << " is divided by 6\n";
        }
        else
        {
            std::cout << "Number: " << number << " is NOT divided by 6\n";
        }
    }
};

int main()
{
    Funktor a{};
    Funktor b{};

    a(18);
    b(8);

    return 0;
}