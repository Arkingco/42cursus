#include "Fixed.hpp"

Fixed::Fixed()
{
    _fixed_point = 0;
}
Fixed::Fixed(const Fixed& other)
{
    *this = other;
}
Fixed::~Fixed()
{
}

Fixed::Fixed(void* null, const int raw_bits)
{
    null = NULL;
    setRawBits(raw_bits);
}

Fixed::Fixed(const int value)
{
    setRawBits(value << _fractional_bit);
}
Fixed::Fixed(const float value)
{
    setRawBits(static_cast<float>(value) * (1 << _fractional_bit));
}
Fixed& Fixed::operator=(const Fixed& other)
{
    _fixed_point = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return _fixed_point;
}
void Fixed::setRawBits(int const raw)
{
    _fixed_point = raw;
}

int Fixed::toInt() const
{
    return (_fixed_point >> _fractional_bit);
}

float Fixed::toFloat() const
{
    return (static_cast<float>(_fixed_point) / (1 << _fractional_bit));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}

bool Fixed::operator==(const Fixed& b)
{
    return this->getRawBits() == b.getRawBits();
}
bool Fixed::operator!=(const Fixed& b)
{
    return this->getRawBits() != b.getRawBits();
}
bool Fixed::operator<(const Fixed& b)
{
    return this->getRawBits() < b.getRawBits();
}
bool Fixed::operator>(const Fixed& b)
{
    return this->getRawBits() > b.getRawBits();
}
bool Fixed::operator<=(const Fixed& b)
{
    return this->getRawBits() <= b.getRawBits();
}
bool Fixed::operator>=(const Fixed& b)
{
    return this->getRawBits() >= b.getRawBits();
}

Fixed Fixed::operator+(const Fixed& b)
{
    return Fixed(NULL, (this->getRawBits() + b.getRawBits()) / (1 << _fractional_bit));
}
Fixed Fixed::operator-(const Fixed& b)
{
    return Fixed(NULL, (this->getRawBits() + b.getRawBits()) / (1 << _fractional_bit));
}
Fixed Fixed::operator*(const Fixed& b)
{
    return Fixed(NULL, (this->getRawBits() * b.getRawBits()) / (1 << _fractional_bit));
}
Fixed Fixed::operator/(const Fixed& b)
{
    return Fixed(NULL, (this->getRawBits() / b.getRawBits()) / (1 << _fractional_bit));
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() <= b.getRawBits())
        return a;
    return b;
}
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() <= b.getRawBits())
        return a;
    return b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() >= b.getRawBits())
        return a;
    return b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() >= b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::operator++()
{
    ++_fixed_point;
    return *this;
}
Fixed Fixed::operator++(int)
{
    _fixed_point++;
    return *this;
}
Fixed& Fixed::operator--()
{
    --_fixed_point;
    return *this;
}
Fixed Fixed::operator--(int)
{
    _fixed_point--;
    return *this;
}
