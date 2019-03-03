#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Rational
{

private:

        //Наибольший общий делитель
        long long
        mcd (long long a_, long long b_)
        {
                long long r_;
                while (b_ != 0) {
                        r_ = a_ % b_;
                        a_ = b_;
                        b_ = r_;
                }
                return a_;
        }

protected:

        int a, b;

        //Сокращение дроби
        void
        reduce (long long & a_, long long & b_)
        {
                long long aux_ = mcd(a_, b_);
                a_ /= aux_;
                b_ /= aux_;
        }

public:

        Rational () :
        a (0), b (1)
        {}

        Rational (int a_, int b_) :
        a (a_), b (b_ ? b_ : 1)
        {}

        Rational (const int &a_) :
        a(a_), b(1)
        {}

        Rational (const Rational & r_) :
        a (r_.a), b (r_.b)
        {}

        Rational &
        Add (const Rational & r_)
        {
                long long a_ = a * r_.b + b * r_.a;
                long long b_ = b * r_.b;
                reduce(a_, b_);
                a = a_;
                b = b_;
                return *this;
        }

        Rational &
        Substract (const Rational & r_)
        {
                Add(Rational(-r_.a, r_.b));
                return *this;
        }

        Rational &
        Multiply (const Rational & r_)
        {
                long long a_ = a * r_.a;
                long long b_ = b * r_.b;
                reduce(a_, b_);
                a = a_;
                b = b_;
                return *this;
        }

        Rational &
        Divide (const Rational & r_)
        {
                if (r_.a != 0) {
                        Multiply(Rational(r_.b, r_.a));
                }
                return *this;
        }

        const bool
        EqualTo (const Rational & r_) const
        {
                return ((a == r_.a) && (b == r_.b));
        }

        const int
        CompareTo (const Rational & r_) const
        {
                Rational q_(*this);
                q_.Substract(r_);
                if (q_.a > 0) {
                        return 1;
                } else if (q_.a == 0) {
                        return 0;
                } else{
                        return -1;
                }
        }

        const bool
        IsInteger () const
        {
                return (b == 1);
        }

        const string
        ToString() const
        {
                int len_ = snprintf(NULL, 0, "%d:%d", a, b);
                char *buf_  = new char[len_ + 1];
                snprintf( buf_, len_ + 1, "%d:%d", a, b);
                string str_(buf_);
                delete[] buf_;
                return str_;
        }
};
