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
    ~Fixed();
    Fixed& operator=(const Fixed& a);

    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
