// Zadanie 💻
// Utwórz wektor v1 z liczbami od 1 do 1000
// Oblicz sumę tych liczb
// Utwórz wektor v2 z 1000 elementów powtarzających się w następującej sekwencji: -1, 0, 1, 0, -1, 0, 1, 0, ...
// Oblicz iloczyn skalarny wektorów v1 i v2
// Oblicz sumę tych liczb z v1, które są na pozycjach dodatnich jedynek z wektora v2

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

int main(){
    std::vector<int> v1 (1000);
    std::iota(v1.begin(), v1.end(), 1);

    // for (auto el: v1)
    // {
    //     std::cout<<el<<'\n';
    // }

    int sum = std::accumulate(v1.begin(), v1.end(), 0);
    std::cout<<"The sum of numbers 1-1000 is: "<<sum<<std::endl;

    std::vector<int> v2 (1000);

    auto st = v2.begin();
    auto ed = std::next(st, 3);

    while(ed < v2.end()){

        std::iota(st, ed, -1);
        *ed = 0;
        
        st = std::next(ed, 1);
        ed = std::next(st, 3); 

    }

    int prd = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
    std::cout<<"The product of vectors v1 and v2 is: "<<prd<<std::endl;

    auto one = [](const auto& first, const auto &second){if(second ==1) return first; return 0;};
    auto p = [](auto first, auto second){return first+second;};
    //int prd1 = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0, std::plus<>(), one);
    int prd1 = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0, p, one);
    std::cout<<"The sum of elements of v1 while on v2 elements are equal to 1 is: "<<prd1<<std::endl;

    return 0;
}