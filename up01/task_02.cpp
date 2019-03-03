#include <iostream>

using namespace std;

void
f (double d, char c = 'a') {
    cout << 2 << endl;
}

void
f (double d, const char *s) {
    cout << 2 << endl;
}
