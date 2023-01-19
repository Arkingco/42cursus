#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

class Array
{
  private:
    int *value;

  public:
    Array();
    Array(int n);
    Array(const Array& a);
    ~Array();
    Array& operator=(const Array& a);

};

#endif
