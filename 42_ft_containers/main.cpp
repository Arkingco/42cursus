#include <iostream>
#include "vector.hpp"
#include <vector>
#include <stack>
#include <type_traits>


int main()
{
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
    ft_vector.push_back(1);
    ft_vector.push_back(2);
    ft_vector.push_back(3);
    ft_vector.push_back(4);
    std_vector.push_back(1);
    std_vector.push_back(2);
    std_vector.push_back(3);
    std_vector.push_back(4);

    for(ft::vector<int>::iterator i = ft_vector.begin(); i != ft_vector.end(); ++i)
    {
        std::cout << *i << std::endl;
    }

    ft_vector[0] = 10;
    std::cout << ft_vector[0] << " " << ft_vector[1] << " " << ft_vector[2] << " " << ft_vector[3] << std::endl;

    ft_vector.at(10) = 10;
    std::cout << ft_vector[0] << " " << ft_vector[1] << " " << ft_vector[2] << " " << ft_vector[3] << std::endl;

    std::cout << ft_vector.front() << " " << ft_vector.back() << std::endl;
    ft_vector.push_back(123);
    ft_vector.push_back(456);
    ft_vector.push_back(789);
    ft_vector.front() = 5;

    std::cout << ft_vector[0] << " " << ft_vector[1] << " " << ft_vector[2] << " " << ft_vector[3]  << std::endl;
    std::cout << ft_vector.front() << " " << ft_vector.back() << std::endl;

    // std::cout << ft_vector[-1] << " " << ft_vector[-2] << " " << ft_vector[5] << " " << ft_vector[4] << std::endl;
    // have to clear this problem
    // ft::is_integral<const int> a;   ft::is_integral<volatile int> a;
}