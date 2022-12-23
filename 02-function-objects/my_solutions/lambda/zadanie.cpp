/* Utwórz lambdę, która przyjmie 2 argumenty typu int oraz zwróci ich iloczyn
Utwórz lambdę, która do podanego ciągu znaków doda cudzysłów. np.
krowa -> "krowa"
Utwórz lambdę, która wypisze ciąg znaków *. Przy każdym zawołaniu funkcji powinniśmy dostać ciąg dłuższy o jedną *. Kolejno:

*
**
***
itd. */

#include <iostream>
#include <string>

int main(){

    auto lb1 = [](int first, int second){return first*second;};

    std::cout<<"Iloczyn 5 i 3 to: "<<lb1(5, 3)<<"\n";

    auto lb2 = [](std::string& str){
        str.insert(str.begin(), '\"');
        str.push_back('\"');
    };

    std::string zwierz = "Krowa";
    lb2(zwierz);
    std::cout<<"Krowa w cudzyslowie to: "<<zwierz<<'\n';

    auto lb2_2 = [](std::string& str){
        str = "\"" + str + "\"";
    };
    lb2_2(zwierz);
    std::cout<<"Krowa w double cudzyslowie to: "<<zwierz<<'\n';

    int index = 1;
    auto lb3 = [&index](){
        for(int i = 0; i < index; i++)
        {
            std::cout<<"*";
        }
        index++;
        std::cout<<"\n";
    };

    lb3();
    lb3();
    lb3();

    std::string gwiazdka = "*";
    auto lb3_2 = [&gwiazdka](){
        std::cout<<gwiazdka;
        gwiazdka += "*";
        std::cout<<"\n";
    };

    lb3_2();
    lb3_2();
    lb3_2();

    return 0;

}