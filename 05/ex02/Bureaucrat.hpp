#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define default_name "Wagie"


class AForm;

class Bureaucrat
{
private:
	const std::string name;
	short int grade;
public:

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw()  {
			return "Grade too high\n";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw()  {
			return "Grade too low\n";
		}
	};
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const std::string &name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat& operator=(const Bureaucrat &obj);
	void incGrade();
	void decGrade();
	short int getGrade() const;
	const std::string &getName() const;
	void signForm(AForm &form);
	void executeForm(AForm const & form) const;

};

std::ostream& operator<<(std::ostream &os, Bureaucrat &b);


#endif