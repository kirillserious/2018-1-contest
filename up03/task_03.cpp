#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string
big_prefix (const string &str)
{
    string prefix;
    for (size_t i = str.size(); i > 0; i--) {
        prefix = str.substr(0, i);
        string tmp = prefix;
        reverse(tmp.begin(), tmp.end());
        if (prefix == tmp) {
            break;
        }
    }
    return prefix;
}

int
main (int argc, char **argv)
{
    string mystr;
    while (cin >> mystr) {
        cout << big_prefix(mystr) << endl;
    }
    return 0;
}