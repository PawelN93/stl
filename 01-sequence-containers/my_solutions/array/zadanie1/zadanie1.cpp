#include <array>
#include <iostream>

int main()
{
    std::array<int, 4> numbers{3, 1, 4, 1};
    std::array<int, 0> no_numbers;
    std::array<int, 3> others;
    std::array<int, 3> init{};

    std::cout << std::boolalpha;
    std::cout << "numbers.empty(): " << numbers.empty() << '\n';
    std::cout << "no_numbers.empty(): " << no_numbers.empty() << '\n';

    std::cout << "others.empty(): " << others.empty() << '\n';
    std::cout << "init.empty(): " << init.empty() << '\n';

    for (const int &el : others)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";

    for (const int &el : init)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";
}