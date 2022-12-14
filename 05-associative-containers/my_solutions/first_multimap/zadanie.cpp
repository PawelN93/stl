#include <iostream>
#include <map>
#include <string>

void display_3char(const std::multimap<int, std::string>::iterator & iter1, const std::multimap<int, std::string>::iterator & iter2)
{

    for(auto index = iter1; index != iter2; index++)
    {
        if (3 == index->second.size())
        {
            std::cout<<index->first<<" | "<<index->second<<'\n';
        }
    }

}

int main()
{
    std::multimap<int, std::string> map;

    map.insert({5, "Ala"});
    map.insert({5, "Ma"});
    map.insert({5, "Kota"});
    map.insert({5, "A"});
    map.insert({5, "Kot"});
    map.insert({5, "Ma"});
    map.insert({5, "Ale"});

    auto [first, second] = map.equal_range(5);

    display_3char(first, second);

    return 0;
}