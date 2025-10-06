#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name(default_name)
{
	this->grade = 150;
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	if(this != &obj)
		this->grade = obj.grade;
	return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	if(grade > 150)
		throw GradeTooLowException();
	if(grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat name and grade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : name(default_name), grade(grade)
{
	if(grade > 150)
		throw GradeTooLowException();
	if(grade < 1)
		throw GradeTooHighException();
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

void Bureaucrat::incGrade()
{
	if(this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade -= 1;
}

void Bureaucrat::decGrade()
{
	if(this->grade + 1 < 150)
		throw GradeTooLowException();
	this->grade += 1;
}


const std::string &Bureaucrat::getName() const
{
	return this->name;
}

short int Bureaucrat::getGrade() const
{
	return this->grade;
}

std::ostream& operator<<(std::ostream &os, Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed form " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->name << " could not execute form " << form.getName() << " [reason:  " << e.what() <<  "]" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed form " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->name << " could not execute form " << form.getName() << " [reason:  " << e.what() <<  "]" << std::endl;
	}
}
