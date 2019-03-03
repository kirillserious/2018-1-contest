#include <string>
#include <cstdio>
#include <cmath>
#include <iostream>

namespace numbers
{
    class complex
    {    
    private:
    
        double re, im;

    public:
    
        friend
        const complex
        operator+ (const complex & a, const complex & b)
        {
            return complex(a.re + b.re, a.im + b.im);
        }

        friend
        const complex
        operator- (const complex & a, const complex & b)
        {
            return complex(a.re - b.re, a.im - b.im);
        }

        friend
        const complex
        operator* (const complex & a, const complex & b)
        {
            return complex(a.re*b.re - a.im*b.im, a.re*b.im + a.im*b.re);
        }

        friend
        const complex
        operator/ (const complex & a, const complex & b)
        {
            double new_re = (a.re*b.re + a.im*b.im)/(b.re*b.re + b.im*b.im);
            double new_im = (b.re*a.im - b.im*a.re)/(b.re*b.re + b.im*b.im);
            return complex(new_re, new_im);
        }

        complex (double _re = 0, double _im = 0):
        re(_re), im(_im)
        {}

        explicit
        complex (const char * str)
        {
            sscanf(str, "(%lf,%lf)", &re, &im);
        }

        double
        get_re() const
        {
            return re;
        }

        double
        get_im () const
        {
            return im;
        }

        double
        abs2 () const
        {
            return re*re + im*im;
        }

        double
        abs () const
        {
            return sqrt(re*re + im*im);
        }

        void
        to_string (char *buf, size_t size) const
        {
            snprintf(buf, size, "(%.10g,%.10g)", re, im);
        }

        const complex
        operator~ () const
        {
            return complex(re, -im);
        }

        const complex
        operator- () const
        {
            return complex(-re, -im);
        }
    };

    class complex_stack
    {
    private:
        struct Container 
        {
            complex *data;
            size_t size;

            void
            deleteData ()
            {
                if (data != nullptr) {
                    delete[] data;
                    data = nullptr;
                }
                size = 0;
            }

            void
            createData (size_t size_)
            {
                data = (size_ == 0) ? nullptr : new complex[size_];
                size = size_;
            }

            Container (size_t size_)
            {
                createData(size_);
            }

            ~Container ()
            {
                deleteData();
            }
        } container_;
               
        size_t size_;

        void
        fillData (const complex_stack & stack, size_t size)
        {
            for (size_t i = 0; i < size; ++i) {
                    container_.data[i] = stack[i];
            }
        }        

    public:
            complex_stack (size_t sz = 0):
            container_ (sz), size_ (sz) {}

            complex_stack (const complex_stack & stack):
            container_ (stack.size_), size_ (stack.size_)
            {
                fillData(stack, stack.size_);
            }

            complex_stack &
            operator= (const complex_stack & stack)
            { 
                container_.deleteData();
                container_.createData(stack.size_);
                fillData(stack, stack.size_);
                size_ = stack.size_;
                return *this;
            }

            size_t
            size () const
            {
                return size_;
            }

            complex &
            operator[] (size_t i) const
            {
                return container_.data[i];
            }

            complex_stack
            operator<< (const complex &z) const
            {
                complex_stack result (size_ + 1);
                result.fillData(*this, size_);
                result[size_] = z;
                return result;
            }

            complex
            operator+ () const
            {
                return (*this)[size_ - 1];
            }

            complex_stack
            operator~ () const
            {
                complex_stack result (size_ - 1);
                result.fillData(*this, size_ - 1);
                return result;
            }
    };

    complex
    eval (char **args, const complex &z)
    {
        complex_stack stack;
        complex a, b;

        for (int i = 0; args[i] != nullptr; ++i) {
            switch (args[i][0]) {
                case '+':
                    a = +stack;
                    stack = ~stack;
                    b = +stack;
                    stack = ~stack;
                    stack = stack << (b + a);
                    break;
                case '-':
                    a = +stack;
                    stack = ~stack;
                    b = +stack;
                    stack = ~stack;
                    stack = stack << (b - a);
                    break;
                case '*':
                    a = +stack;
                    stack = ~stack;
                    b = +stack;
                    stack = ~stack;
                    stack = stack << (b * a);
                    break;
                case '/':
                    a = +stack;
                    stack = ~stack;
                    b = +stack;
                    stack = ~stack;
                    stack = stack << (b / a);
                    break;
                case '!':
                    stack = stack << (+stack);
                    break;
                case ';':
                    stack = ~stack;
                    break;
                case '~':
                    a = +stack;
                    stack = ~stack;
                    stack = stack << ~a;
                    break;
                case '#':
                    a = +stack;
                    stack = ~stack;
                    stack = stack << -a;
                    break;
                case '(':
                    stack = stack << complex(args[i]);
                    break;
                case 'z':
                    stack = stack << z;
                    break;
                default:
                    break;
            }   
        }
        return +stack;
    }
}

inline
numbers::complex
make_circle_dot (const numbers::complex & c, double r, int n, int i)
{
    double re = c.get_re() + r*cos(2*M_PI*i/n);
    double im = c.get_im() + r*sin(2*M_PI*i/n);
    return numbers::complex(re, im);
}

enum { MAX_COMPLEX_STRING_SIZE = 50 };

int
main (int argc, char **argv)
{
    using namespace numbers;

    complex c = complex (argv[1]);
    double  r = std::stod(argv[2]);
    int     n = std::stoi(argv[3]);
    char  **f = &(argv[4]);


    complex result;
    
    for (int i = 0; i < n; ++i) {
        complex x = make_circle_dot(c, r, n, i);
        complex y = make_circle_dot(c, r, n, i+1);
        result = result + eval(f, (x + y) / 2) * (x - y);
    }
    

    char buf[MAX_COMPLEX_STRING_SIZE];
    result.to_string(buf, MAX_COMPLEX_STRING_SIZE);
    std::cout << buf << std::endl;
    return 0;
}