#include "templates.hpp"
#include <cstdlib>
#include <iostream>

int	main(int ac, char **av)
{
	// if(ac == 3)
	// {
	// 	//int val = std::atoi(av[1]), val2 = std::atoi(av[2]);
	// 	std::string s1 = av[1], s2 = av[2];
	// 	//swap<int>(&val, &val2);
	// 	swap<std::string>(s1, s2);
	// 	std::cout << "swapped: " << s1 << " " <<  s2 << std::endl;
	// }

	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	templates::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << templates::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << templates::max(c, d) << std::endl;
	return (0);
}