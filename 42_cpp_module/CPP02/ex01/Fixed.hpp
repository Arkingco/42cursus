#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
  private:
    int              _fixed_point;
    static const int _fractional_bit = 8;

  public:
    Fixed();
    Fixed(const Fixed& a);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();
    Fixed& operator=(const Fixed& a);

    float  toFloat() const;
    int    toInt() const;
    int    getRawBits(void) const;
    void   setRawBits(int const raw);
    Fixed& operator<<(const Fixed& a);
};

#endif
