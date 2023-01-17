#include <iostream>
#include "Data.hpp"
#include <bitset>

uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
} 

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

int main()
{
    Data A("my name is kipark");

    uintptr_t uintprt_t_serialize = serialize(&A);

    Data* B = deserialize(uintprt_t_serialize);

    std::cout << "before serialize : " << A.getData() << std::endl;
    std::cout << "after deserialize : " << B->getData() << std::endl;
}