#include <cstdio>
#include <cmath>
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

                complex ():
                re(0), im(0)
                {}

                complex (double _re):
                re(_re), im(0)
                {}

                complex (double _re, double _im):
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




}