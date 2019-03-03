/* Тип языка первый:  a^m 0^n b^m 1^n, n>0 m>0 */

#include <cstdio>
#include <cctype>
#include <iostream>

enum state_type
{
    H, A, Z, B, O, ST_TRUE, ST_FALSE, ST_EOF
};

class Scanner
{
    int c;

    void
    get () { c = getc(stdin); }

    void
    go_to_space ()
    {
        while (!isspace(c)) {
            get();
        }
    }
public:
    Scanner () { get(); }

    bool get_word ()
    {
        state_type state = H;
        int m = 0;
        int n = 0;

        while (true) {

            switch (state) {
                case H:
                    if (c == 'a') {
                        get();
                        state = A;
                        m++;
                        break;
                    } else if (isspace(c)) {
                        get();
                        break;
                    } else if (c == EOF) {
                        throw ST_EOF;
                    } else {
                        go_to_space();
                        return false;
                    }
                case A:
                    if (c == 'a') {
                        get();
                        state = A;
                        m++;
                        break;
                    } else if (c == '0') {
                        get();
                        state = Z;
                        n++;
                        break;
                    } else if (c == EOF) {
                        throw ST_FALSE;
                    } else {
                        go_to_space();
                        return false;
                    }
                case Z:
                    if (c == '0') {
                        get();
                        state = Z;
                        n++;
                        break;
                    } else if (c == 'b') {
                        get();
                        state = B;
                        m--;
                        break;
                    } else if (c == EOF) {
                        throw ST_FALSE;
                    } else {
                        go_to_space();
                        return false;
                    }
                case B:
                    if (c == 'b') {
                        get();
                        state = B;
                        m--;
                        break;
                    } else if (c == '1') {
                        get();
                        state = O;
                        n--;
                        break;
                    } else if (c == EOF) {
                        throw ST_FALSE;
                    } else {
                        go_to_space();
                        return false;
                    }
                case O:
                    if (c == '1') {
                        get();
                        n--;
                        state = O;
                        break;
                    } if (isspace(c) && (m==0) && (n==0)) {
                        get();
                        return true;
                    } else if (c == EOF) {
                        throw ST_TRUE;
                    } else {
                        go_to_space();
                        return false;
                    }                
                default:
                    break;
        }}
    }
};

int
main ()
{
    Scanner scanner;
    while (true) {
        try {
            std::cout << scanner.get_word() << std :: endl;
        } catch (state_type st) {
            switch (st) {
                case ST_TRUE:
                    std::cout << 1 << std :: endl;
                    break;
                case ST_FALSE:
                    std::cout << 0 << std::endl;
                    break; 
                default:
                    break;
            }
            break;
        }
    }
}