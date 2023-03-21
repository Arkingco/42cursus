#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : c_start(0), c_end(0)
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}
