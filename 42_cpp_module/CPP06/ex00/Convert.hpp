#ifndef Convert_HPP
#define Convert_HPP

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <iomanip>

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
