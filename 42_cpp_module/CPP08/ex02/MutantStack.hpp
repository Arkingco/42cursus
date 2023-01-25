#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
	 
  public:
		typedef typename std::stack<T>::container_type::iterator 				iterator;
		typedef typename std::stack<T>::container_type::const_iterator 			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator 		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;


    MutantStack()
    {
  	}

    MutantStack(const MutantStack& other)
	{
		this->c.assign(other.begin(), other.end());
		return *this;
	}

    ~MutantStack()
	{
	}
	
    MutantStack& operator=(const MutantStack& other)
	{
		if (this == &other)
        	return *this;
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

	const_iterator begin() const
	{
		return (this->c.begin());
	}

	const_iterator egin() const
	{
		return (this->c.begin());
	}

	reverse_iterator rbegin()
	{
		return (this->c.rbegin());
	}

	reverse_iterator rend()
	{
		return (this->c.rend());
	}

	const_reverse_iterator rbegin() const
	{
		return (this->c.rbegin());
	}

	const_reverse_iterator rend() const
	{
		return (this->c.rend());
	}
};


#endif
