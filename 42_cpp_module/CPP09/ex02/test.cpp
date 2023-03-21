#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
 
// the function f() does some time-consuming work
void f()
{
    volatile double d = 0;
    for(int n=0; n<100000; ++n)
       for(int m=0; m<10000; ++m) {
           double diff = d*n*m;
           d = diff + d;
       }
}
 
int main()
{
    std::clock_t c_start = std::clock();
    f();
	f();
    std::clock_t c_end = std::clock();
 
    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              <<  (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";
}