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
Część B - trudniejsza
Skopiuj te dane do mapy std::map<Point, std::string>
Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu 70 od środka układu współrzędnych (0, 0)
Pobierz i wypisz współrzędne Sydney */

#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>

struct Point;
double radius(Point p);

struct Point
{
    const int x;
    const int y;

/*  bool operator<(const Point &other) const
    {
        // return x < other.x && y < other.y;
        return radius(*this) < radius(other);
    } */
};

double radius(Point p)
{
    return std::sqrt(p.x * p.x + p.y * p.y);
}

int main()
{

  /*  std::map<const Point, std::string> mapka = {
        {{17, 51}, "Wroclaw"},
        {{37, 55}, "Moskwa"},
        {{-74, 40}, "Nowy Jork"},
        {{151, -33}, "Sydney"}}; */

        auto compRadius = [] (const auto & lhs, const auto & rhs){
            return radius(lhs) < radius(rhs);
        };

    /* std::map<Point, std::string, decltype(compRadius)> mapka = {{
        {{17, 51}, "Wroclaw"},
        {{37, 55}, "Moskwa"},
        {{-74, 40}, "Nowy Jork"},
        {{151, -33}, "Sydney"}
        }, compRadius}; */ 

        std::map<Point, std::string, decltype(compRadius)> mapka(compRadius);

        mapka.insert({{151, -33}, "Sydney"});
        mapka.insert({{-74, 40}, "Nowy Jork"});
        mapka.insert({{37, 55}, "Moskwa"});
        mapka.insert({{17, 51}, "Wroclaw"});


    auto it = mapka.begin();

    do
    {
        it = std::find_if(it, mapka.end(), [](const auto iter)
                          { return (sqrt(iter.first.x * iter.first.x + iter.first.y * iter.first.y) <= 70); });

        if (it != mapka.end())
        {
            std::cout << it->second << " | " << it->first.x << ": " << it->first.y << '\n';
            it++;
        }
    } while (it != mapka.end());

    auto syd = std::find_if(mapka.begin(), mapka.end(), [](auto m)
                            { return m.second == "Sydney"; });

    std::cout << "Coordinates of Sydney are: " << syd->first.x << ": " << syd->first.y << std::endl;

    return 0;
}