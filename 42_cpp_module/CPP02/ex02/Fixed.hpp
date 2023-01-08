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
    Fixed(void* null, const int raw_bits);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    const static Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       min(Fixed& a, Fixed& b);
    const static Fixed& max(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);

    float toFloat() const;
    int   toInt() const;
    int   getRawBits(void) const;
    void  setRawBits(int const raw);

    Fixed& operator=(const Fixed& a);
    Fixed& operator++();
    Fixed  operator++(int);
    Fixed& operator--();
    Fixed  operator--(int);

    bool  operator==(const Fixed& b);
    bool  operator!=(const Fixed& b);
    bool  operator<(const Fixed& b);
    bool  operator>(const Fixed& b);
    bool  operator<=(const Fixed& b);
    bool  operator>=(const Fixed& b);
    Fixed operator+(const Fixed& b);
    Fixed operator-(const Fixed& b);
    Fixed operator*(const Fixed& b);
    Fixed operator/(const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
