#include <iostream>
#include "vector.hpp"
#include <vector>
#include <stack>
int main()
{
    ft::vector<int> hi(2, 10);

    std::cout << *hi.begin() << " " << *hi.end() << " " << hi.capacity() << std::endl;
    for(ft::vector<int>::iterator i = hi.begin(); i != hi.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
}