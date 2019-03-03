#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int
main (void)
{
    double sqr_sum = 0;
    double simple_sum = 0;
    int count = 0;

    double x;
    while (cin >> x) {
        simple_sum += x;
        sqr_sum += x * x;
        count++;
    }

    double ans = simple_sum / count;
    cout << setprecision(11)
            << ans
            << " "
            << sqrt((sqr_sum - 2*ans*simple_sum + count*ans*ans) / count)
            << endl;

    return 0;
}