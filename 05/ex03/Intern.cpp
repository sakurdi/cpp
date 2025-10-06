#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	(void)obj;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &obj)
{
	(void)obj;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::createForm(const std::string &formName, const std::string &target)
{
	std::string formNames[] = 
	{
		"ShrubberyCreation",
		"RobotomyRequest",
		"PresidentialPardon"
	};
	AForm* (Intern::*formArray[])(const std::string &) = 
	{
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern (wagie) creates " << formName << std::endl;
			return (this->*formArray[i])(target);
		}
	}
	std::cout << "Error: Form \"" << formName << "\" does not exist" << std::endl;
	return NULL;
}