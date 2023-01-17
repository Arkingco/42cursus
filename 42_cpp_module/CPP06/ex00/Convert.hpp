#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <limits>
#include <cmath>

class Convert
{
  private:
    std::string input;
    double      to_double;
    Convert();
    void ConvertChar();
    void ConvertInt();
    void ConvertFloat();
    void ConvertDouble();

  public:
    Convert(std::string input);
    Convert(const Convert& a);
    ~Convert();
    Convert& operator=(const Convert& a);
    void printConvert();
};

#endif
