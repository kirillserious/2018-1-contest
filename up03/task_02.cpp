#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

void
process(const vector<int> & vctr1, list<int> & lst)
{   
    if (vctr1.begin() == vctr1.end()) return;
    vector<int> vctr = vctr1;
    sort(vctr.begin(), vctr.end());
    vector<int>::iterator last_it = unique(vctr.begin(), vctr.end());
    

    vector<int>::iterator it_vctr = vctr.begin();
    while ((*it_vctr <= 0)&&(it_vctr < last_it)) it_vctr++;

    list<int>::iterator it_lst = lst.begin();
    
    int i = 1;
    while ((it_vctr < last_it) && (it_lst != lst.end())) {
        if (*it_vctr == i) {
            list<int>::iterator tmp = it_lst;
            tmp++;
            it_lst = lst.erase(it_lst, tmp);
            it_vctr++;            
        } else {
            it_lst++;
        }
        i++;
    }
}
