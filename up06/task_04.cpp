#include <iostream>
#include <cmath>
#include <algorithm>

int
main ()
{
    using namespace std;

    int n, m;
    cin >> n >> m;
    
    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        int x_way = min({abs(x1 - x2), abs(x1 - x2 - n), abs(x1 - x2 + n)});
        int y_way = min({abs(y1 - y2), abs(y1 - y2 - m), abs(y1 - y2 + m)});
        cout << x_way + y_way << endl;
    }

    return 0;
}