#include <iostream>
#include <vector>

using namespace std; 

void
process(vector<int> & v)
{ 
        for (auto i = v.begin(); i != v.end();) {
                i = v.erase(i);
                if (i != v.end()) ++i;
        }

        for (auto i = v.rbegin(); i != v.rend(); ++i) {
                cout << *i << endl;
        }
}
