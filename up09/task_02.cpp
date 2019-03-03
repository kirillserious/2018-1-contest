#include <cstdio>
#include <cctype>
#include <iostream>

enum state_type
{
    H, A, AB, AC, ABC, AS, ABS, ACS, ABCS, ST_EOF, ST_FALSE, ST_TRUE
};

class Scanner
{
    int c;

    void    get         () { c = getc(stdin); }
    void    go_to_space ()
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

        while (true) {
            switch (state) {
                case H   :
                    if (c == '0') {
                        get();
                        state = A;
                        break;
                    } else if (c == '1') {
                        get();
                        state = AB;
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
                case A   :
                    if (c == '0') {
                        get();
                        state = A;
                        break;
                    } else if (c == '1') {
                        get();
                        state = AB;
                        break;
                    } else if (isspace(c)) {
                        get();
                        return false;
                    } else if (c == EOF) {
                        throw ST_FALSE;
                    } else {
                        go_to_space();
                        return false;
                    }
                case AB  :
                    if (c == '0') {
                        get();
                        state = AC;
                        break;
                    } else if (c == '1') {
                        get();
                        state = ABC;
                        break;
                    } else if (isspace(c)) {
                        get();
                        return false;
                    } else if (c == EOF) {
                        throw ST_FALSE;
                    } else {
                        go_to_space();
                        return false;
                    }
                case AC  :
                    if (c == '0') {
                        get();
                        state = AS;
                        break;
                    } else if (c == '1') {
                        get();
                        state = ABS;
                        break;
                    } else if (isspace(c)) {
                        get();
                        return false;
                    } else if (c == EOF) {
                        throw ST_FALSE;
                    } else {
                        go_to_space();
                        return false;
                    }
                case ABC :
                    if (c == '0') {
                        get();
                        state = ACS;
                        break;
                    } else if (c == '1') {
                        get();
                        state = ABCS;
                        break;
                    } else if (isspace(c)) {
                        get();
                        return false;
                    } else if (c == EOF) {
                        throw ST_FALSE;
                    } else {
                        go_to_space();
                        return false;
                    }
                case AS  :
                    if (c == '0') {
                        get();
                        state = AS;
                        break;
                    } else if (c == '1') {
                        get();
                        state = AB;
                        break;
                    } else if (isspace(c)) {
                        get();
                        return true;
                    } else if (c == EOF) {
                        throw ST_TRUE;
                    } else {
                        go_to_space();
                        return false;
                    }
                case ABS :
                    if (c == '0') {
                        get();
                        state = AC;
                        break;
                    } else if (c == '1') {
                        get();
                        state = ABC;
                        break;
                    } else if (isspace(c)) {
                        get();
                        return true;
                    } else if (c == EOF) {
                        throw ST_TRUE;
                    } else {
                        go_to_space();
                        return false;
                    }
                case ACS :
                    if (c == '0') {
                        get();
                        state = AS;
                        break;
                    } else if (c == '1') {
                        get();
                        state = ABS;
                        break;
                    } else if (isspace(c)) {
                        get();
                        return true;
                    } else if (c == EOF) {
                        throw ST_TRUE;
                    } else {
                        go_to_space();
                        return false;
                    }
                case ABCS:
                    if (c == '0') {
                        get();
                        state = ACS;
                        break;
                    } else if (c == '1') {
                        get();
                        state = ABCS;
                        break;
                    } else if (isspace(c)) {
                        get();
                        return true;
                    } else if (c == EOF) {
                        throw ST_FALSE;
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