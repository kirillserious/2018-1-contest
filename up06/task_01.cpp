#include <iostream>

class Container
{
    int number;
public:
    Container  (int number) :
    number (number) 
    {}

    ~Container ()
    {
        std::cout << number << " ";
    }
};

void
recurcion ()
{
    int number;
    if (std::cin >> number) {
        Container container (number);
        recurcion();
    } else {
        throw 0;
    }

}

int
main ()
{
    try {
        recurcion();
    } catch (...) {
        std::cout << std::endl;
    }
   
}

