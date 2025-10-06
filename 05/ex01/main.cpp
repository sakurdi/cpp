#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Bureaucrat b(1);
	Bureaucrat a("Bonsoir");
	std::cout << b << std::endl << a << std::endl;
	Form f;
	std::cout << a << std::endl;
	b.signForm(f);
	a.signForm(f);
}