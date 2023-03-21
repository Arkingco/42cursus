#ifndef PMERGEME
# define PMERGEME

#include <stack>
#include <vector>
#include <ctime>
#include <iostream>
#include <cstdlib>

class PmergeMe
{
  private:

  public:
    PmergeMe();
    PmergeMe(const PmergeMe& a);;
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& a);

};

#endif