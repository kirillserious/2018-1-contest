#include <iostream>
#include <list>
#include <vector>

using namespace std;

void process(const vector<int> &_vector, list<int> &_list, int step)
{   
    if (_list.size() == 0) return;

    int n = step - 1;
    auto l_it = _list.begin();
    for (auto v_it = _vector.begin(); v_it != _vector.end(); ++v_it) {
        ++n;
        if (n == step) {
            n = 0;
            if (l_it == _list.end()) {
                break;
            }
            *l_it = *v_it;
            ++l_it;
        }
    }

    for (auto it = --_list.end(); it != _list.begin(); --it) {
            cout << *it << ' ';
    }
    cout << *(_list.begin()) << endl;
}