#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	int number;
	static int const fractional_val = 8;

public:
	Fixed();
	Fixed(const Fixed &obj);
	~Fixed();
	Fixed(const int val);
	Fixed(const float val);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed &operator=(const Fixed &obj);
	bool operator<(const Fixed &obj) const;
	bool operator>(const Fixed &obj) const;
	bool operator<=(const Fixed &obj) const;
	bool operator>=(const Fixed &obj) const;
	bool operator==(const Fixed &obj) const;
	bool operator!=(const Fixed &obj) const;
	Fixed operator+(const Fixed &obj) const;
	Fixed operator-(const Fixed &obj) const;
	Fixed operator*(const Fixed &obj) const;
	Fixed operator/(const Fixed &obj) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
