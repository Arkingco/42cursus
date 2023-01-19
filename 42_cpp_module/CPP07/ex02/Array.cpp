#include "Array.hpp"

Array::Array()
{
    
}

Array::Array(int n)
{
    
}

Array::Array(const Array& other)
{
    *this = other;
}

Array::~Array()
{
}

Array& Array::operator=(const Array& other)
{
    if (this == &other)
        return *this;
    std::cout << "Array Assignment Operator Call" << std::endl;
    return *this;
}
