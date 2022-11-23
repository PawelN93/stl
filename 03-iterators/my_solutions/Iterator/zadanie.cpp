#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

auto middle(auto first, auto last)
{
    auto size = distance(first, last);
    size /= 2;
    auto mid = first;
    advance(mid, size);

    return (mid);
}

int main()
{
    vector<int> vec{1, 4, 3, 6, 5};
    auto f = vec.begin();
    auto l = vec.end();

    list<int> lista{1, 2, 6, 4, 5};
    auto lf = lista.begin();
    auto ll = lista.end();

    forward_list<int> f_lista{1, 2, 3, 4, 5, 6};
    auto ff = f_lista.begin();
    auto fl = f_lista.end();

    deque<int> kolejka{1, 2, 70, 4, 10};
    auto df = kolejka.begin();
    auto dl = kolejka.end();

    auto m = middle(f, l);

    auto mi = middle(lf, ll);
    auto midi = middle(ff, fl);

    auto mididek = middle(df, dl);

    cout << "vector" << endl;
    cout << *m << endl;

    cout << "lista" << endl;
    cout << *mi << endl;

    cout << "forward_list" << endl;
    cout << *midi << endl;

    cout << "deque" << endl;
    cout << *mididek << endl;

    return 0;
}
