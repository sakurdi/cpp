#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	int number;
	static int const fractional_val = 8;
public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &obj);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
