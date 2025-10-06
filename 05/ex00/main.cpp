#include "Bureaucrat.hpp"

int main()
{

	try
	{
		Bureaucrat b(1);
		Bureaucrat a("Bonsoir");
		std::cout << b << std::endl << a << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

}