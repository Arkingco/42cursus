#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
  private:
    uintptr_t data;

  public:
    Data();
    Data(uintptr_t data);
    Data(const Data& a);
    ~Data();
    Data& operator=(const Data& a);
};

#endif
