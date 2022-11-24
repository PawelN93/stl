/* Zadanie — przeszukiwanie 💻
Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9}; (ten sam co ostatnio)
Znajdź wszystkie elementy większe od 6 i wypisz je
Znajdź wszystkie elementy równe 2, 4, 6 lub 8 i wypisz je
Przeszukaj wektor v w poszukiwaniu zakresów {6, 6} i {7, 7}
Użyj std::adjacent_find na wektorze v */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    std::cout << "1.------------------------\n";
    auto it = v.begin();

    while (it != v.end())
    {
        it = std::find_if(it, v.end(), [](auto n)
                          { return n > 6; });

        if (it != v.end())
        {
            std::cout << *it << " ";
            it++;
        }
    }
    std::cout << std::endl;
    std::cout << "2.------------------------\n";
    std::array<int, 4> arr = {2, 4, 6, 8};

    it = v.begin();
    int index{1};

    while (it != v.end())
    {
        it = std::find_first_of(it, v.end(), arr.begin(), arr.end());
        if (it != v.end())
        {
            std::cout << index << ". " << *it << " | ";
            it++;
            index++;
        }
    }
    std::cout << std::endl;
    std::cout << "3a.------------------------\n";
    std::array<int, 2> range1 = {6, 6};
    std::array<int, 2> range2 = {7, 7};

    it = v.begin();

    it = std::search(it, v.end(), range1.begin(), range1.end());
    while (it != v.end())
    {
        std::cout << *it << " ";
        it++;
        it = std::search(it, v.end(), range1.begin(), range1.end());
    }
    std::cout << std::endl;
    std::cout << "3b.------------------------\n";
    it = v.begin();

    it = std::search(it, v.end(), range2.begin(), range2.end());
    while (it != v.end())
    {
        std::cout << *it << " ";
        it++;
        it = std::search(it, v.end(), range2.begin(), range2.end());
    }
    std::cout << std::endl;
    std::cout << "4.------------------------\n";
    it = v.begin();
    it = std::adjacent_find(it, v.end());
    while (it != v.end())
    {
        std::cout << *it << " ";
        it++;
        it = std::adjacent_find(it, v.end());
    }
    std::cout << std::endl;
    return 0;
}
