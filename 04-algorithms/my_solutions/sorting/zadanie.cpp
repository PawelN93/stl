/*Zadanie 💻
struct Point { int x, y; }
Utwórz std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};
Utwórz funkcję do wypisywania zawartości kontenera d
Napisz 2 komparatory:
pointXCompare, który porównuje tylko wartości x ze struktury Point
pointYCompare, który porównuje tylko wartości y ze struktury Point
Sprawdź czy d jest posortowane względem pointXCompare oraz pointYCompare
Użyj stable_sort do posortowania d względem wartości x
Użyj sort do posortowania d względem wartości y*/

#include <iostream>
#include <algorithm>
#include <deque>

struct Point
{
    int x, y;
};

void display(const std::deque<Point> &pkt)
{
    for (const auto &el : pkt)
    {
        std::cout << "{X: " << el.x << " Y: " << el.y << "}   ";
    }

    std::cout << '\n';
}

int main()
{
    std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};

    display(d);

    auto pointXCompare = [](const Point &first, const Point &second)
    { return first.x < second.x; };
    auto pointYCompare = [](const Point &first, const Point &second)
    { return first.y < second.y; };

    std::cout << "Is sorted according pointXCompare: ";
    if (std::is_sorted(d.begin(), d.end(), pointXCompare))
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    std::cout << "Is sorted according pointYCompare: ";
    if (std::is_sorted(d.begin(), d.end(), pointYCompare))
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    std::stable_sort(d.begin(), d.end(), pointXCompare);
    std::cout << "After stable_sort according pointXCompare:\n";
    display(d);
    std::cout << "Is sorted according pointXCompare: ";
    if (std::is_sorted(d.begin(), d.end(), pointXCompare))
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    std::sort(d.begin(), d.end(), pointYCompare);
    std::cout << "After sort according pointYCompare:\n";
    display(d);

    std::cout << "Is sorted according pointYCompare: ";
    if (std::is_sorted(d.begin(), d.end(), pointYCompare))
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    return 0;
}