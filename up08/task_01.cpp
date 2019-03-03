#include <iostream>
#include <string>

using namespace std;

int
main ()
{
    string s;
    while (cin >> s) {
        int i = 0;
        while ((s[i] == '3') || (s[i] == '4')) {
            i++;
        }
        if (s[i] == '\0') {
            cout << 1 << endl;
            continue;
        }
        while ((s[i] == '1') || (s[i] == '2')) {
            i++;
        }
        if (s[i] == '\0') {
            cout << 1 << endl;
            continue;
        }
        cout << 0 <<endl;
    }
    return 0;
}