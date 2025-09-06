#include "Fixed.hpp"

int main( void ) 

{
Fixed a(2.500f);
std::cout << a.getRawBits() << std::endl;
return 0;
}