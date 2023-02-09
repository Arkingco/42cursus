#include <iostream>
#include "vector.hpp"
#include <vector>
#include <stack>
#include <type_traits>


template<typename iterator>
void print_vector(iterator start, iterator end)
{
    std::cout << "-------- print vector --------" << std::endl;
    for (iterator i = start; i != end; ++i)
    {
        std::cout << *i << std::endl;
    }
}

#include <sstream> //
void test_ft_vector()
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

    int *vector_pointer = ft_vector.data();
    
    for (int i=0; i<ft_vector.size(); ++i)
    {
        std::cout << "vector_pointer : " << vector_pointer[i] << std::endl;
    }

    
    ft::vector<std::string> hi2;

    hi2.push_back("hi");
    hi2.push_back("my");
    hi2.push_back("name");
    hi2.push_back("is");
    hi2.push_back("kipark");
    hi2.erase(hi2.begin());
    std::cout << "hi man : " <<hi2[0] << std::endl;
    print_vector(hi2.begin(), hi2.end());
    hi2.clear();

    hi2.push_back("그래");
    hi2.push_back("나다");
    hi2.push_back("이놈아");
    print_vector(hi2.begin(), hi2.end());
    

    std::vector<int> test;

    test.push_back(1);
    test.push_back(1);
    test.push_back(1);
    test.push_back(1);


    ft::vector<int> hh(1000);

    hh.push_back(1);
    hh.push_back(2);
    hh.push_back(3);
    hh.push_back(4);
    hh.push_back(5);
    hh.push_back(6);
    hh.push_back(7);
    hh.push_back(7);
    hh.push_back(7);

    print_vector(hh.begin(), hh.end());
    hh.insert(hh.begin(), 11);
    hh.insert(hh.begin(), 12);
    hh.insert(hh.begin(), 13);
    hh.insert(hh.begin(), 14);
    hh.insert(hh.begin(), 15);
    hh.insert(hh.begin(), 16);
    hh.insert(hh.begin(), 17);
    print_vector(hh.begin(), hh.end());

    hh.insert(hh.end(), 5, 5);
    print_vector(hh.begin(), hh.end());

    std::istringstream str("11234 331232 441233 4444 5 6 7");
    hh.insert(hh.begin(), std::istream_iterator<int>(str), std::istream_iterator<int>());

    print_vector(hh.begin(), hh.end());


    hh.erase(hh.begin());
    print_vector(hh.begin(), hh.end());

    hh.erase(hh.begin(), hh.end());
    print_vector(hh.begin(), hh.end());

}