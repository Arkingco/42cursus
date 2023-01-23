#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void iter(T *address, const int length, void (*f)(T const &))
{
    for (int i=0; i<length; ++i)
        f(address[i]);
}

#endif
