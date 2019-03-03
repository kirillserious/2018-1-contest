#include <string>
#include <sstream>
#include <cmath>

#include <vector>
#include <iostream>
#include <algorithm>
#include <typeinfo>


int
main ()
{
    using namespace std;

    vector <Figure*> v;

    string s;
    while (std :: getline(std :: cin, s)) {
        istringstream in (s);
        char c;
        in >> c;
        getline(in, s); 
        
        switch (c) {
        case 'S' :
            v.push_back(Square :: make(s));
            break;
        case 'R' :
            v.push_back(Rectangle :: make(s));
            break;
        case 'C' :
            v.push_back(Circle :: make(s));
            break;
        default:
            cout << "Что-то не так, не S, R, C" << endl;
        }
    }  

    stable_sort(v.begin(), v.end(), [] (Figure *a, Figure *b){
        return a->get_square() < b->get_square(); 
    });


    int size = v.size();
    for (int i = 0; i < size; ++i) {
        if (auto ptr = dynamic_cast<Square*> (v[i])) {
            cout << ptr->to_string() << endl;
            delete ptr;
        } else if (auto ptr = dynamic_cast<Rectangle*> (v[i])) {
            cout << ptr->to_string() << endl;
            delete ptr;
        } else if (auto ptr = dynamic_cast<Circle*> (v[i])) {
            cout << ptr->to_string() << endl;
            delete ptr;
        }        
    }
    
    return 0;
}