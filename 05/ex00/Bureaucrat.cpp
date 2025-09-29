#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(default_name)
{
	this->grade = 150;
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : name(default_name), grade(grade)
{
	if(grade > 150 || grade < 0)
		throw 
	std::cout << "Bureaucrat grade constructor called with value: " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name) : name(name)
{
	this->grade = 150;
	std::cout << "Bureaucrat name constructor called with value: " << name << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return this->name;
}

short int Bureaucrat::getGrade() const
{
	return this->grade;
}