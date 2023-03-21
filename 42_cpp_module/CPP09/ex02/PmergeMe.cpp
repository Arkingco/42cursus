#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
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
 void PmergeMe::set_c_start(std::clock_t time)
{
	c_start = time;
}
void PmergeMe::set_c_stop(std::clock_t time)
{
	c_stop = time;
}
double PmergeMe::get_algorithm_time()
{
	std::cout << " " << c_stop << " " << c_start << " " << c_stop - c_start<< std::endl;
	return ((c_stop - c_start) / CLOCKS_PER_SEC);
}
