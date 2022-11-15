#include <iostream>
#include <forward_list>

void print_list(const std::forward_list<int> &l)
{

    for (const auto &el : l)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::forward_list<int> lista{0, 1, 2, 3, 4, 5, 6};

    print_list(lista);

    lista.erase_after(++lista.begin());
    print_list(lista);

    lista.emplace_after(lista.before_begin(), 10);
    // lista.emplace_front(10);
    auto it = lista.before_begin();
    for (const auto &el : lista)
    {
        ++it;
    }
    lista.emplace_after(it, 10);

    /* lista.reverse();
     lista.emplace_after(lista.before_begin(), 10);
     lista.reverse();*/
    print_list(lista);

    it = lista.begin();
    std::advance(it, 3);
    lista.emplace_after(it, 20);
    print_list(lista);

    return 0;
}