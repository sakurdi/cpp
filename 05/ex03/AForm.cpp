#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name(default_name), sign_grade(1), exec_grade(1), is_signed(0)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &obj) : name(obj.name), sign_grade(obj.sign_grade), exec_grade(obj.exec_grade), is_signed(obj.is_signed)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &obj)
{
	if(this != &obj)
		this->is_signed = obj.is_signed;
	return *this;
}

AForm::AForm(const std::string &name, short int s_grade, short int e_grade) : name(name), sign_grade(s_grade), exec_grade(e_grade), is_signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	std::cout << "AForm with params constructor called" << std::endl;
}


AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->sign_grade)
		throw GradeTooLowException();
	this->is_signed = true;
}

const std::string& AForm::getName() const
{
	return this->name;
}

bool AForm::getisSigned() const
{
	return this->is_signed;
}

int AForm::getSignGrade() const
{
	return this->sign_grade;
}

int AForm::getExecGrade() const
{
	return this->exec_grade;
}

std::ostream& operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm name : " << f.getName() << " | grade to sign : " 
	<< f.getSignGrade() << " | grade to execute : " << f.getExecGrade()
	<< " | is AForm signed : " << f.getisSigned();
	
	return os;
}

void AForm::CheckExecRights(const Bureaucrat &e) const
{
	if (!this->is_signed)
		throw FormNotSignedException();
	if (e.getGrade() > this->exec_grade)
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &e) const
{
	CheckExecRights(e);
	executeAction();
}
