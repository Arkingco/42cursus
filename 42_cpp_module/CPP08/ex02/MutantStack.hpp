#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

class MutantStack
{
  private:
    unsigned int N;
    std::vector<int> elements;
    MutantStack();

  public:
    MutantStack(unsigned int N);
    MutantStack(const MutantStack& a);
    ~MutantStack();
    MutantStack& operator=(const MutantStack& a);
};

class TooManyElement : public std::exception
{
	virtual const char * what() const throw();
};

#endif
