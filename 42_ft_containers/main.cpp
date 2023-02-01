#include <iostream>
#include "vector.hpp"
#include <vector>
#include <stack>
#include <type_traits>


int main()
{
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
    ft_vector.push_back(10);
    ft_vector.push_back(10);
    ft_vector.push_back(10);
    ft_vector.push_back(10);
    std_vector.push_back(10);
    std_vector.push_back(10);
    std_vector.push_back(10);
    std_vector.push_back(10);
    std_vector.push_back(10);

    for(ft::vector<int>::iterator i = ft_vector.begin(); i != ft_vector.end(); ++i)
    {
        std::cout << *i << std::endl;
    }

    ft::is_integral<volatile int> a;
    std::cout << a.value << std::endl;
}