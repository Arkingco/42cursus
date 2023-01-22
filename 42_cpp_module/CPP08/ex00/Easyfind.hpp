#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>

class IncorrectTypeEexception : public std::exception
{
	virtual const char * what() const throw(){
		return "IncorrectType !!";
	}
};

class NotMatched : public std::exception
{
	virtual const char * what() const throw(){
		return "NotMatched !!";
	}
};

template<typename T>
typename T::iterator easyfind(T &iter, int num)
{
	if (typeid(iter) != typeid(std::vector<int>))
		throw IncorrectTypeEexception();
	typename T::iterator find;
	
	find = std::find(iter.begin(), iter.end(), num);
	if (find == iter.end())
		throw NotMatched();
	return find;
}

#endif