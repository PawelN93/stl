/* Zadanie 💻
Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
Usuń wszystkie duplikaty z v
Wypisz wszystkie elementy, używając std::copy i std::ostream_iterator
Pomieszaj losowo wszystkie elementy
Wypisz je raz jeszcze */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

int main()
{
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<'\n';

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<"\n";

    return 0;
}