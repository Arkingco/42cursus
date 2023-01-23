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

bool ft_isdigit(std::string str, double to_double)
{
    if (str.length() == 0)
        return false;
    if (to_double == 0)
    {
        if (str.length() == 1 && str[0] == '0')
            return true;
        return false;
    }
    return true;
}


Convert::Convert() 
{
}

Convert::Convert(const Convert& other)
{
    *this = other;
}

Convert::~Convert()
{
}

Convert& Convert::operator=(const Convert& other)
{
    if (this == &other)
        return *this;
    return *this;
}

Convert::Convert(std::string input) : input(input)
{
    to_double = strtod(input.c_str(), NULL);

     if (ft_isinf(to_double))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float : " << static_cast<float>(to_double) << "f" << std::endl;
        std::cout << "double: " << to_double << std::endl;
    }
    else if (ft_isnan(to_double) || !ft_isdigit(input, to_double))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float : nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
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
    if (to_double <= -2147483649.0 || to_double >= 2147483648.0)
        std::cout << "int: impossible" << std::endl;
    else{
        std::cout << "int: " << i << std::endl;
    }
}

void Convert::ConvertFloat()
{
    float f = static_cast<float>(to_double);
    if (f == static_cast<int>(f) && (to_double < 1000000.0 && to_double > -1000000.0) )
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << f << "f" << std::endl;
}

void Convert::ConvertDouble()
{
    double d = static_cast<double>(to_double);
    if (d == ceil(d))
        std::cout << std::setprecision(std::numeric_limits<double>::digits10) << "dobule: " << d << ".0" << std::endl;
    else
        std::cout << std::setprecision(std::numeric_limits<double>::digits10) << "dobule: " << d << std::endl;
}