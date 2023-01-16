#include "Convert.hpp"

bool    ft_isnan(float f)
{
    return (f != f);
}

bool    ft_isinf(float f)
{
    return (f != 0 && f * 2 == f);
}

bool    ft_isnan(double d)
{
    return (d != d);
}

bool    ft_isinf(double d)
{
    return (d != 0 && d * 2 == d);
}

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
    to_double = strtod(input.c_str(), NULL);

    std::cout << to_double << std::endl;
    if (ft_isinf(to_double))
    {
        std::cout << "ft_isinf" << std::endl;
    }
    else if (ft_isnan(to_double))
    {
        std::cout << "if_isnan" << std::endl;
    }
    else 
    {
        ConvertChar();
        ConvertInt();
        ConvertFloat();
        ConvertDouble();
    }
}

void Convert::ConvertChar()
{
    char c = static_cast<char>(to_double);
    if (to_double < 0 || to_double > 127)
        std::cout << "char: impossible" << std::endl;
    else if (c < 32 || c == 127)
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << c << std::endl;
}

void Convert::ConvertInt()
{
    int i = static_cast<int>(to_double);
    if (to_double < -214748369 || to_double > 2147483648)
        std::cout << "int: impossible" << std::endl;
    else{
        std::cout << "int: " << i << std::endl;
    }
}

void Convert::ConvertFloat()
{
    float f = static_cast<float>(to_double);
    std::cout << "float: " << (double)f << "f" << std::endl;
}

void Convert::ConvertDouble()
{
    float d = static_cast<double>(to_double);
    d = d + 0.000;
    std::setprecision(5);
    std::cout << "double: " << (double)d << std::endl;
}

void Convert::printConvert()
{

    double a = 0;
    double b = 1.1;
    double c = 10;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}