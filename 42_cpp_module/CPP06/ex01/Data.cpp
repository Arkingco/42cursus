#include "Data.hpp"

Data::Data()
{
}

// Data::Data(uintptr_t data) : data(data)
// {

// }

Data::Data(const Data& other)
{
    *this = other;
}

Data::~Data()
{
}

Data& Data::operator=(const Data& other)
{
    if (this == &other)
        return *this;
    std::cout << "Data Assignment Operator Call" << std::endl;
    return *this;
}
