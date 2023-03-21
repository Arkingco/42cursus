#ifndef PMERGEME
# define PMERGEME

#include <stack>
#include <vector>
#include <ctime>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <iomanip>
class PmergeMe
{
  private:
    std::clock_t c_start;
    std::clock_t c_stop;

  public:
    PmergeMe();
    PmergeMe(const PmergeMe& a);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& a);

    void set_c_start(std::clock_t time);
    void set_c_stop(std::clock_t time);
    double get_algorithm_time();

};

#endif