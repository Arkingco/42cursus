#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _fixed_point = 0;
}
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(value << _fractional_bit);
}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits(value * (1 << _fractional_bit));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
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
