#include <iostream>
#include <list>
#include <array>

void print_list(const std::list<int> &l)
{
    for (const auto &el : l)
    {
        std::cout << el << " ";
    }

    std::cout << "\n";
}

int main()
{

    std::list<int> lista{0, 1, 2, 3, 4, 5};

    print_list(lista);

    auto it = lista.begin();
    std::advance(it, 2);

    lista.erase(it);
    print_list(lista);

    lista.emplace_front(10);
    lista.emplace_back(10);

    print_list(lista);
    it = lista.begin();
    std::advance(it, 4);

    lista.emplace(it, 20);
    print_list(lista);

    std::array<int, 8> tab;

    int i = 0;
    for (const auto &el : lista)
    {
        tab[i] = el;
        i++;
    }
    std::cout << "Tablica\n";
    for (const auto &el : tab)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";

    return 0;
}