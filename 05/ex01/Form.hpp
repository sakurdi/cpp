#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#define default_name "Wagie"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	const short int sign_grade;
	const short int exec_grade;
	bool is_signed;
public:
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw()  {
			return "Grade too high";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw()  {
			return "Grade too low";
		}
	};
	Form();
	Form(std::string &name, short int e_grade, short int s_grade);
	~Form();
	Form(const Form &obj);
	Form& operator=(const Form &obj);
	void beSigned(const Bureaucrat &bureaucrat);
	bool getisSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	const std::string& getName() const;


};

std::ostream& operator<<(std::ostream &os, Form &f);



#endif