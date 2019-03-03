#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int
main ()
{
        vector <string> v;
        map <string, int> m;
        string s;

        int i = 1;
        while (cin >> s){
                if (s[s.size()-1] != ':') {
                        v.push_back(s);

                        i++;
                } else {
                        m.insert({s, i});
                }
        }

        for (auto i = v.begin(); i != v.end(); ++i) {
                auto q = m.find(*i + ':');
                if (q == m.end()) {
                        cout << *i << endl;
                } else {
                        cout << q->second << endl;
                }

        }
        return 0;
}