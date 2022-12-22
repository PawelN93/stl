/* Zadanie:
Znajdź dokumentację std:deque na cppreference.com
Stwórz nowy plik i napisz funkcję main()
Stwórz pusty deque
Dodaj do niego pięć dowolnych wartości
Wyświetl deque
Usuń drugi i czwarty element
Dodaj na początek i koniec wartość 30
Wyświetl deque
Dodaj na czwartej pozycji liczbę 20
Wyświetl deque */

#include <iostream>
#include <deque>

int main()
{

    std::deque<int> kolejka;

    kolejka.push_back(10);
    kolejka.push_back(15);
    kolejka.push_back(20);
    kolejka.push_back(25);
    kolejka.push_back(30);

    for (const auto &el : kolejka)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    kolejka.erase(kolejka.begin() + 3);
    kolejka.erase(kolejka.begin() + 1);

    kolejka.push_front(30);
    kolejka.push_back(30);

    for (const auto &el : kolejka)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    kolejka.insert(kolejka.begin() + 4, 20);
    for (const auto &el : kolejka)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}