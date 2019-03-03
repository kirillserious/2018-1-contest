#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

enum
{
        THREAD_CNT = 3,
        ITERATION_CNT = 1000000
};

double  a[THREAD_CNT];
mutex   m; 

void
thread_func (int num)
{
        std::lock_guard<mutex> lc(m);
        for (int i = 0; i < ITERATION_CNT; ++i) {
                switch (num) {
                        case 0:
                        a[0] += 100;
                        a[1] -= 101;
                        break;
                        case 1:
                        a[1] += 200;
                        a[2] -= 201;
                        break;
                        case 2:
                        a[2] += 300;
                        a[0] -= 301;
                }
        }
}

int
main ()
{
        vector<thread> v;
        for (int i = 0; i < THREAD_CNT; ++i)
                v.emplace_back(thread(thread_func, i));
        for (auto  &i : v)
                i.join();
        for (double i : a)
                printf("%.10g\n", i);
        return 0;
}