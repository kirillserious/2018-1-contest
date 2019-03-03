#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class
function
{
private:
    double _result;
    int _size;
public:
    function (int size):
    _size(size)
    {}

    double
    get_result (void)
    {
        return _result;
    }

    void
    operator() (double number)
    {
        _result += number / _size;
    }
};

inline
void
scan_vector (vector <double> &v) {
    double number;
    while (cin >> number) {
        v.insert(v.end(), number);
    }
}

inline
void
offset_iterators (
        vector<double>::iterator &start,
        vector<double>::iterator &finish,
        int offset)
{
    for (int i = 0; i < offset; i++) {
        start++;
        finish--;
    }
}

enum {OFFSET_PERCENT = 10};

int
main (void)
{
    vector <double> v;
    scan_vector(v);

    int size = v.size();
    vector<double>::iterator start = v.begin();
    vector<double>::iterator finish = v.end();

    int offset = v.size() / OFFSET_PERCENT;
    size -= 2 * offset;
    offset_iterators(start, finish, offset);
    sort(start, finish);
    offset = size / OFFSET_PERCENT;
    size -= 2 * offset;
    offset_iterators(start, finish, offset);
    function f(size);
    f = for_each(start, finish, f);

    cout << f.get_result() << endl;

    return 0;
}