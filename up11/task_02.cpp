#include <iostream>
#include <cstdio>

using namespace std;

/*
 *  S -> 1A0
 *  A -> 1A0 | 0B1
 *  B -> 0B1 | eps
 */

class Parser {

int c;

void get () {c = getchar(); }

void B ()
{
        if (c == '0') {
                putchar('1');
                get();
                B();
                if (c == '1') {
                        putchar('0');
                        get();
                }
        } else if (isspace(c)) {
                get();
                return;
        }
}

void A ()
{
        if (c == '1') {
                get();
                A();
                if (c == '0') {
                        putchar('0');
                        get();
                }
        } else if (c == '0') {
                putchar('1');
                get();
                B();
                if (c == '1') {
                        putchar('0');
                        get();
                }
        }
}

void S ()
{
        if (c == '1') {
                get();
                A();
                if (c == '0') {
                        putchar('0');
                        putchar('\n');
                        get();
                }
        }
}
public:
        Parser ()
        { 
                get();
                while (c != EOF){
                        S();
                        while(isspace(c)) {
                                get();
                        }
                } 
        }

};


int
main ()
{
        Parser parser;
        return 0;
}