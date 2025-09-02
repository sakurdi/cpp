#include "Fixed.hpp"

Fixed::Fixed()
{
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
    }
    return *this;
}

Fixed::~Fixed()
{
}
