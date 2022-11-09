#include <iostream>
#include <vector>
#include <algorithm>

void delete_first(std::vector<int> &w)
{
    auto value = w[0];

    auto it = std::remove(w.begin(), w.end(), value);
    w.erase(it, w.end());
}

void print_vec(const std::vector<int> &w)
{
    for (const auto &el : w)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}
int main()
{
    std::vector<int> vec{1, 2, 4, 5, 6};

    print_vec(vec);
    delete_first(vec);
    print_vec(vec);

    vec.push_back(5);
    print_vec(vec);
    vec.emplace(vec.begin(), 12);
    // vec.insert(vec.begin(), 12);
    print_vec(vec);

    std::cout << "Rozmiar wektora to: " << vec.size() << std::endl;
    std::cout << "Max mozliwy rozmiar wektora to: " << vec.max_size() << std::endl;

    vec.erase(vec.begin(), vec.end());
    std::cout << "Rozmiar wektora po czyszczeniu to: " << vec.size() << std::endl;

    return 0;
}