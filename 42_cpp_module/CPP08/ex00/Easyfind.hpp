#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

class NotMatched : public std::exception
{
	virtual const char * what() const throw(){
		return "NotMatched !!";
	}
};

template<typename T>
typename T::iterator easyfind(T &iter, int num)
{
	typename T::iterator find;
	find = std::find(iter.begin(), iter.end(), num);
	if (find == iter.end())
		throw NotMatched();
	return find;
}

#endif