#include <iostream>
#include <vector>

using namespace std;

vector<char> v;

void
f (int k, int flag)
{
    if (!k) {        
        for (auto i = v.rbegin(); i != v.rend(); ++i) {
            cout << *i;
        }
        cout << endl;
        return;
    }

    v[k - 1] = '1';
    f(k - 1, 1);
    v[k - 1] = '2';
    f(k - 1, 1);

    if (!flag) {
        v[k - 1] = '3';
        f(k - 1, 0);
        v[k - 1] = '4';
        f(k - 1, 0);
    }
}

int
main ()
{
    int k;
    cin >> k;
    v.resize(k);
    f(k, 0);

    return 0;
}