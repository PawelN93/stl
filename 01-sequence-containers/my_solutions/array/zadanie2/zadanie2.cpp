#include <iostream>
#include <array>

int main()
{
    std::array<int, 10> tab{};

    tab.fill(5);
    tab[3] = 3;

    std::array<int, 10> arr{};

    arr = tab;
    // tab.swap(arr);

    std::cout << "Zawartosc 1 tablicy: " << std::endl;

    for (const auto &el : tab)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";

    std::cout << "Zawartosc 2 tablicy: " << std::endl;

    for (const auto &el : arr)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";

    return 0;
}
