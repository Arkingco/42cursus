#include <iostream>
#include "Data.hpp"
#include <bitset>

uintptr_t serialize(Data* ptr)
{
    std::cout << ptr << std::endl;
} 

Data* deserialize(uintptr_t raw)
{
    std::cout << raw << std::endl;
}

int main()
{
    uintptr_t a;
    Data *b;
    uintptr_t c;
    std::cout << sizeof(Data *) << std::endl;
    a = 10;
    
    b = reinterpret_cast<Data *>(&a);
    c = reinterpret_cast<uintptr_t>(b);
    std::cout << &a << " " << c << std::endl;
}