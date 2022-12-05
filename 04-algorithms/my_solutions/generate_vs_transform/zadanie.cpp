/* Zadanie 💻
Utwórz poniższy wektor:

 std::vector<std::pair<int, std::string>> v {
     {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}
 };
Utwórz wektor intów v2 i wypełnij go wszystkimi intami (pierwszymi elementami pary) z wektora v

Utwórz wektor stringów v3 i wypełnij go konkatenacją string + dwukropek + int ze wszystkich par z wektora v
Utwórz wektor charów v4 i wypełnij go co drugą literą alfabetu
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::pair<int, std::string>> v{
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};

    std::vector<int> v2{};

    std::transform(v.begin(), v.end(), std::back_inserter(v2), [](auto vec)
                   { return vec.first; });

    for (const auto &el : v2)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::vector<std::string> v3;

    std::transform(v.begin(), v.end(), std::back_inserter(v3), [](auto vec)
                   { return vec.second + ": " + (std::to_string(vec.first)); });

    for (const auto &el : v3)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    /*std::vector<char> v4;

    std::generate_n(std::back_inserter(v4), 13, [c = 'a' - 2]() mutable
                    { return c += 2; });
*/
    constexpr size_t size = 13;
    std::vector<char> v4(size);

    std::generate(v4.begin(), v4.end(), [c = 'a' - 2]() mutable
                  { return c += 2; });

    for (const auto &el : v4)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    return 0;
}
