#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
	 
  public:
  	typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack()
    {
    	std::cout << "MutantStack Constructor Call" << std::endl;
  	}

    MutantStack(const MutantStack& other)
	{
		std::cout << "MutantStack copy Constructor Call" << std::endl;
		this->c.assign(other.begin(), other.end());
		return *this;
	}

    ~MutantStack()
	{
	    std::cout << "MutantStack Destructor Call" << std::endl;
	}
	
    MutantStack& operator=(const MutantStack& other)
	{
		if (this == &other)
        	return *this;
		std::cout << "MutantStack Assignment Operator Call" << std::endl;
		this->c.assign(other.c.begin(), other.c.end());
		return *this;
	}

	iterator begin()
	{
		return (this->c.begin());
	}

	iterator end()
	{
		return (this->c.end());
	}
};


#endif
