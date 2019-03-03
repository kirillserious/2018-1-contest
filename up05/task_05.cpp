#include <string>
#include <sstream>
#include <cmath>

class Square : public Figure
{
    double _a;
    Square (double a) :
    _a (a)
    {}

public:
    static
    Square*
    make (const std::string &str)
    {
        std::istringstream in (str);
        double a = 0;
        in >> a;

        return new Square(a);
    }

    virtual
    double
    get_square () const
    {
        return _a * _a;
    }
};


class Rectangle : public Figure
{  
    double _a, _b;

    Rectangle (double a, double b) :
    _a (a), _b (b) {}

public:
    static
    Rectangle*
    make (const std::string &str)
    {
        std::istringstream in (str);
        double a = 0, b = 0;
        in >> a >> b;

        return new Rectangle(a, b);
    }

    virtual
    double
    get_square () const
    {
        return _a * _b;
    }
};


class Circle : public Figure
{
    double _r;

    Circle (double r) :
    _r (r)
    {}

public:

    static
    Circle*
    make (const std::string &str)
    {
        std::istringstream in (str);
        double r = 0;
        in >> r;

        return new Circle(r);
    }

    virtual
    double
    get_square () const
    {
        return M_PI * _r * _r;
    }
};