#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T& a, T& b)
{
    T temp;
    temp = b;
    b = a;
    a = temp;
}

template<typename T>
T min(T a, T b)
{
    return a >= b ? b : a;
}

template<typename T>
T max(T a, T b)
{
    return a >= b ? a : b;
}

#endif
