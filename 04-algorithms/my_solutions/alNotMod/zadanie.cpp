#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

    auto five = [](auto n)
    { return n >= 5; };
    auto five_count = std::count_if(v.begin(), v.end(), five);

    std::cout << "Bigger or equal 5 count is: " << five_count << std::endl;

    auto one = [](auto n)
    { return n < 1; };
    auto less_one = std::any_of(v.begin(), v.end(), one);

    if (less_one)
    {
        std::cout << "There is element smaller than 1\n";
    }
    else
    {
        std::cout << "There is NO element smaller than 1\n";
    }

    auto one_2 = [](auto n)
    { return n > 1; };
    auto bigger_one = std::all_of(v.begin(), v.end(), one_2);
    if (bigger_one)
    {
        std::cout << "There are all elements bigger than 1\n";
    }
    else
    {
        std::cout << "There are NOT all elements bigger than 1\n";
    }

    return 0;
}