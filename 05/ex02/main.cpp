#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(0));
	std::cout << "********* ShrubberyCreationForm *********" << std::endl;
	try
	{
		Bureaucrat Aragorn("Der Gartner", 140);
		ShrubberyCreationForm shrub("Jardin");
		
		std::cout << shrub << std::endl;
		Aragorn.signForm(shrub);
		Aragorn.executeForm(shrub);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught, reason: " << e.what() << std::endl;
	}

	std::cout << "\n********* RobotomyRequestForm *********" << std::endl;
	try
	{
		Bureaucrat Heimer("Donger", 40);
		RobotomyRequestForm golem("Blitzcrank");
		
		std::cout << golem << std::endl;
		Heimer.signForm(golem);
		Heimer.executeForm(golem);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught, reason: " << e.what() << std::endl;
	}

	std::cout << "\n********* PresidentialPardonForm *********" << std::endl;
	try
	{
		Bureaucrat president("Donald", 1);
		PresidentialPardonForm pardon("Epstein (deja mort)");
		
		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught, reason: " << e.what() << std::endl;
	}

	std::cout << "********* Unsigned form attempt *********" << std::endl;
	try
	{
		Bureaucrat kingpin("Pingouin", 1);
		ShrubberyCreationForm shrub("Underworld");
		
		std::cout << "Attempting to execute unsigned form:" << std::endl;
		kingpin.executeForm(shrub);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught, reason: " << e.what() << std::endl;
	}

	std::cout << "\n********* Grade too low exception *********" << std::endl;
	try
	{
		Bureaucrat Jesse("Jesse", 150);
		PresidentialPardonForm pardon("Le lache Robert Ford");
		
		Jesse.signForm(pardon);
		Jesse.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught, reason: " << e.what() << std::endl;
	}

	std::cout << "\n********* Grade too low to exec *********" << std::endl;
	try
	{
		Bureaucrat manager("Manager", 20);
		Bureaucrat intern("Intern", 50);
		PresidentialPardonForm pardon("Nullard");
		
		manager.signForm(pardon);
		intern.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught, reason: " << e.what() << std::endl;
	}

	std::cout << "\n********* Odd/even Robotomy *********" << std::endl;
	try
	{
		Bureaucrat Cacochyme("Mendiant", 1);
		
		for (int i = 0; i < 5; i++)
		{
			RobotomyRequestForm Egrotant("Souffreteux");
			Cacochyme.signForm(Egrotant);
			Cacochyme.executeForm(Egrotant);
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught, reason: " << e.what() << std::endl;
	}

	return 0;
}