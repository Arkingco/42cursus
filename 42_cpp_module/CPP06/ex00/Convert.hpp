#ifndef Convert_HPP
#define Convert_HPP

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Convert
{
  private:
    std::string input;
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
