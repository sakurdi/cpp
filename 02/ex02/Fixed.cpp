#include "Fixed.hpp"

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->number = val << this->fractional_val;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->number = roundf(val * (1 << this->fractional_val));
}

Fixed::Fixed() : number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->number = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->number / (1 << this->fractional_val);
}

int Fixed::toInt(void) const
{
	return (int)this->number >> this->fractional_val;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->number < obj.getRawBits());
}

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->number > obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->number <= obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->number >= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->number == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->number != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed result;
	result.setRawBits(this->number + obj.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed result;
	result.setRawBits(this->number - obj.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed result;
	long long temp = (long long)this->number * obj.getRawBits();
	result.setRawBits((int)(temp >> this->fractional_val));
	return result;
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed result;
	if (obj.getRawBits() == 0)
	{
		std::cerr << "Division by 0" << std::endl;
		result.setRawBits(0);
		return result;
	}
	long long div = ((long long)this->number << this->fractional_val) / obj.getRawBits();
	result.setRawBits((int)div);
	return result;
}

Fixed &Fixed::operator++(void)
{
	this->number += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed res(*this);
	this->number += 1;
	return res;
}

Fixed &Fixed::operator--(void)
{
	this->number -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->number -= 1;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}