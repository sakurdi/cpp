#include "Bureaucrat.hpp"

int main()
{

	try
	{
		Bureaucrat b(0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

}