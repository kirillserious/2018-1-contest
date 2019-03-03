#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

inline
int
percent (int a, int b)
{
    return (1000*a/b  + 5) / 10;
}

int
main (void)
{
    uint32_t population;
    cin >> population;

    map<string, int> m = {
            {"napoleon", 0},
            {"loshad", 0},
            {"zhir", 0},
            {"balyk", 0},
            {"grusha", 0}
        };

    int incorrect = 0;
    int all_votes = 0;

    string s;
    while (cin >> s) {
        ++all_votes;
        try {
            ++m.at(s);
        } catch(...) {
            ++incorrect;
        }
    }


    cout << percent(all_votes, population) << endl;
    cout << percent(incorrect, all_votes)  << endl;

    std::vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b) -> bool {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    });

    for_each(v.begin(), v.end(), [&](const pair<string, int> &a){
        cout << a.first << ' ' << percent(a.second, all_votes) << endl;
    });

    return 0;
}