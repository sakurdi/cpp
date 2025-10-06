#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &obj);
	Intern& operator=(const Intern &obj);
	~Intern();
	AForm* createForm(const std::string &formName, const std::string &target);
private:
	AForm* createShrubberyForm(const std::string &target);
	AForm* createRobotomyForm(const std::string &target);
	AForm* createPresidentialForm(const std::string &target);
};

#endif