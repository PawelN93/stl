/* Zadanie
struct Point {
  int x;
  int y;
}
Struktura Point ma reprezentować punkt o współrzędnych x i y na mapie. Mamy też dane 4 miast:

Wrocław (x = 17, y = 51)
Moskwa (x = 37, y = 55)
Nowy Jork (x = -74, y = 40)
Sydney (x = 151, y = -33)
Część A - łatwiejsza
Stwórz std::map<std::string, Point>, która będzie przechowywać powyższe miejsca
Sprawdź czy w mapie jest element, który znajduje się w promieniu 70 od środka układu współrzędnych (0, 0)
Pobierz i wypisz współrzędne Sydney */

#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>

struct Point{
    int x;
    int y;
};

int main(){

    std::map<std::string, Point> mapka;

    mapka.insert({"Wroclaw", {17, 51}});
    mapka.insert({"Moskwa", {37, 55}});
    mapka.insert({"Nowy Jork", {-74, 40}});
    mapka.insert({"Sydney", {151, -33}});

    auto it = mapka.begin();

    do{
    it = std::find_if(it, mapka.end(), [](auto iter){ return (sqrt(iter.second.x*iter.second.x+iter.second.y*iter.second.y) <= 70);});

   
    if(it != mapka.end())
    {
        std::cout<<it->first<<" | "<<it->second.x<<": "<<it->second.y<<'\n';
        it++;
    }
    } while(it != mapka.end()); 

    auto& c = mapka["Sydney"];

    std::cout<<"Coordinates of Sydney are: "<<c.x<<": "<<c.y<<std::endl;



    return 0;
}