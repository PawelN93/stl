#include <iostream>
#include <vector>

void print_size_capacity(const std::vector<int> &w)
{
    std::cout << "Rozmiar wektora to: " << w.size() << std::endl;
    std::cout << "Pojemnosc wektora to: " << w.capacity() << std::endl;
}

int main()
{
    std::vector<int> vec{};
    print_size_capacity(vec);

    vec.resize(10, 5);
    std::cout << "Po funkcji resize(10, 5)" << std::endl;
    print_size_capacity(vec);

    vec.reserve(20);
    std::cout << "Po funkcji reserve(20)" << std::endl;
    print_size_capacity(vec);

    vec.shrink_to_fit();
    std::cout << "Po funkcji shrink_to_fit()" << std::endl;
    print_size_capacity(vec);

    std::cout<<"Zawartosc wektora: "<<std::endl;

    for (const auto &el : vec)
    {
        std::cout << el << " ";
    }
    std::cout<<std::endl;

    return 0;
}