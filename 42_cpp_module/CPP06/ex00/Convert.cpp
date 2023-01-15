#include "Convert.hpp"


Convert::Convert() 
{
    std::cout << "Convert Constructor Call" << std::endl;
}

Convert::Convert(const Convert& other)
{
    std::cout << "Convert Constructor Call" << std::endl;
    *this = other;
}

Convert::~Convert()
{
    std::cout << "Convert Destructor Call" << std::endl;
}

Convert& Convert::operator=(const Convert& other)
{
    if (this == &other)
        return *this;
    std::cout << "Convert Assignment Operator Call" << std::endl;
    return *this;
}

Convert::Convert(std::string input) : input(input)
{
    std::cout << "Convert Constructor Call" << std::endl;
}

void ConvertChar()
{
    
}

void ConvertInt()
{

}

void ConvertFloat()
{

}

void ConvertDouble()
{
    
}