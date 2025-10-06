#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form() : name(default_name), sign_grade(1), exec_grade(1), is_signed(0)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &obj) : name(obj.name), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade), is_signed(obj.is_signed)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &obj)
{
	if(this != &obj)
		this->is_signed = obj.is_signed;
	return *this;
}


Form::Form(std::string &name, short int e_grade, short int s_grade) :
name(name), sign_grade(s_grade), exec_grade(e_grade), is_signed(0)
{
	if(e_grade < 1 || sign_grade < 1)
		throw GradeTooHighException();
	if(e_grade > 150 || sign_grade > 150)
		throw GradeTooLowException();
	std::cout << "Form parameterized constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->sign_grade)
		throw GradeTooLowException();
	this->is_signed = true;
}

const std::string& Form::getName() const
{
	return this->name;
}

bool Form::getisSigned() const
{
	return this->is_signed;
}

int Form::getSignGrade() const
{
	return this->sign_grade;
}

int Form::getExecGrade() const
{
	return this->exec_grade;
}

std::ostream& operator<<(std::ostream &os, Form &f)
{
	std::cout << "Form name : " << f.getName() << " grade to sign : " 
	<< f.getSignGrade() << " grade to execute : " << f.getExecGrade()
	<< "is form signed : " << f.getisSigned();
	
	return os;
}