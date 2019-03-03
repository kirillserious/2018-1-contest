#include <iostream>

class Result
{
    int number;
public:
    Result (int number) :
    number (number)
    {}

    operator int ()
    {
        return number;
    }
};

void
akkerman (int m, int n)
{
    if (m == 0) {
        throw Result (n + 1);
    } else if (n == 0) {
        akkerman(m - 1, 1);
    } else {
        try {
            akkerman(m, n - 1);
        } catch (Result &result) {
            akkerman(m - 1, result);
        }
    }
}

int
main ()
{
    int m, n;
    std::cin >> m >> n;

    try {
        akkerman (m, n);
    } catch (Result &res) {
        std::cout << res << std::endl;
    }
}