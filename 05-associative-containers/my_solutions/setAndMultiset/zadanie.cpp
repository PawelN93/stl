/* Zadanie
Wygeneruj zbiór liczb od -20 do 20 i zapisz go w std::set w kolejności malejącej
Wstaw nowe elementy: -10, 0, 10, 100, -100
Wygeneruj drugi zbiór z liczb od 0 do 40 i zapisz go w std::multiset
Wstaw nowe elementy: -10, 0, 10, 100, -100
Połącz oba zbiory w jeden (ma to być std::multiset)
Znajdź wszystkie elementy równe 0 i 50
Co każdy krok wypisuj zawartości kontenerów. */

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::set<int, std::greater<int>> st;
    std::vector<int> v(41);

    std::iota(v.begin(), v.end(), -20);

    std::for_each(v.begin(), v.end(), [&st](auto &n)
                  { st.insert(n); });

    // std::transform(v.begin(), v.end(), std::inserter(st, st.end()), [](auto iter){return iter;});

    for (const auto &el : st)
    {
        std::cout << el << " ";
    }
    std::cout << '\n';

    st.insert(-10);
    st.insert(0);
    st.insert(10);
    st.insert(100);
    st.insert(-100);

    for (const auto &el : st)
    {
        std::cout << el << " ";
    }
    std::cout << '\n';

    std::iota(v.begin(), v.end(), 0);

    std::multiset<int> multist {v.begin(), v.end()};

   // std::iota(v.begin(), v.end(), 0);

/*     std::for_each(v.begin(), v.end(), [&multist](auto &n)
                  { multist.insert(n); }); */

    for (const auto &el : multist)
    {
        std::cout << el << " ";
    }
    std::cout << '\n';

    multist.insert(-10);
    multist.insert(0);
    multist.insert(10);
    multist.insert(100);
    multist.insert(-100);

    for (const auto &el : multist)
    {
        std::cout << el << " ";
    }
    std::cout << '\n';

    std::multiset<int> merged {multist.begin(), multist.end()};

    for (const auto &el : merged)
    {
        std::cout << el << " ";
    }
    std::cout << '\n'<<"---------------------------------------------------------------\n";

    merged.merge(st);

    for (const auto &el : merged)
    {
        std::cout << el << " ";
    }
    std::cout << '\n';
    std::cout << '\n'<<"---------------------------------------------------------------\n";

    auto [L0, U0] = std::equal_range(merged.begin(), merged.end(), 0);

    std::cout<<"Found 0s: "<<std::distance(L0, U0)<<'\n';

    while (L0 != U0)
    {
        std::cout<<*L0<<" ";
        L0++;
    }
    std::cout << '\n';

    auto [L50, U50] = std::equal_range(merged.begin(), merged.end(), 50);

    std::cout<<"Found 50s: "<<std::distance(L50, U50)<<'\n';

    while (L50 != U50)
    {
        std::cout<<*L50<<" ";
        L50++;
    }
    std::cout << '\n';

    return 0;
}