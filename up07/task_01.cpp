#include <iostream>

using namespace std;

int
main ()
{
    char c, prev = 0;
    int cnt = 0;
    while (cin >> noskipws >> c) {
        if (!prev) {
            prev = c;
        }

        if (c == prev) {
            ++cnt;
        } else {
            if (prev == '#' || cnt > 4) {
                cout << '#' << prev << hex << cnt << '#';
            } else {
                for (int i = 0; i < cnt; ++i) {
                    cout << prev;
                }
            }                                
            prev = c;
            cnt = 1;
        }
    }

    if (prev == '#' || cnt > 4) {
        cout << '#' << prev << hex << cnt << '#';
    } else {
        for (int i = 0; i < cnt; ++i) {
            cout << prev;
        }
    }
    prev = c;
    cnt = 1;

    return 0;
}