#include <complex>
#include <vector>
#include <array>



namespace Equations {
    using namespace std;

    template <typename T>
    pair<bool, vector<complex<T>>>
    quadratic (const array<complex<T>, 3> &arr)
    {
        const complex<T>& a = arr[2];
        const complex<T>& b = arr[1];
        const complex<T>& c = arr[0];
        const complex<T> zero (0,0);
        pair<bool, vector<complex<T>>> result;

        if (a == zero && b == zero && c == zero) {
            result.first = false;
            return result;
        } else if (a == zero && b == zero) {
            result.first = true;
            return result;
        } else if (a == zero) {
            result.first = true;
            result.second.push_back(-c/a);
            return result;
        } else {

        }
        return pair<bool, vector<complex<T>>>();

    }
}
#include <iostream>

int main()
{
    std::array<std::complex<double>, 3> v1{
        std::complex<double>(1.0, 2.0),
        std::complex<double>(2.0, 0),
        std::complex<double>(0, 0)
    };

    auto res = Equations::quadratic(v1);
    std::cout << res.second[0];
}