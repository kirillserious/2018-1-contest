#include <cmath>
#include <algorithm>

template <typename T>
class Coord
{
public:
    typedef T value_type;
    T row, col;

    Coord (const T &row = 0, const T &col = 0) :
    row (row), col (col)
    {}
};

template <typename T>
int
dist (const Coord<T> &size, const Coord<T> &a, const Coord<T> &b)
{
    int x_way = std::min({
            abs(a.col - b.col), 
            abs(a.col - b.col - size.col),
            abs(a.col - b.col + size.col)
    });

    int y_way = std::min({
            abs(a.row - b.row),
            abs(a.row - b.row - size.row),
            abs(a.row - b.row + size.row)
    });

    return std::min(x_way, y_way) + abs(x_way - y_way);
} 