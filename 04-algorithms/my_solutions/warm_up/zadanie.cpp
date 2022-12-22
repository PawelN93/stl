// Utwórz std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
// Utwórz lambdę, która przechwyci ten wektor i wyświetli jego zawartość
// Utwórz lambdę, która przyjmie int jako argument i wyświetli go
// Użyj lambdy z pkt. 3 w algorytmie std::for_each() do wyświetlenia zawartości całego kontenera

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto lb = [&v](){
        for (const auto& el : v)
        {
            std::cout<<el<<" ";
        }
        std::cout<<"\n";
    };

    lb();

    auto lbd = [](int arg){std::cout<<arg<<" ";};

    std::for_each(v.begin(), v.end(), lbd);
    std::cout<<"\n";

}