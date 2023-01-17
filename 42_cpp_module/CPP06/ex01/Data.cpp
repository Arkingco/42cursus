#include "Data.hpp"

Data::Data()
{
}

Data::Data(std::string data) : data(data)
{

}

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

std::string Data::getData()
{
    return (data);
}