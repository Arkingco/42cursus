#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
  private:
    std::string data;

  public:
    Data();
    Data(std::string data);
    Data(const Data& a);
    ~Data();
    Data& operator=(const Data& a);

    std::string getData();
};

#endif
