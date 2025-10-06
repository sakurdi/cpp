#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#define default_name "Wagie"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	const short int sign_grade;
	const short int exec_grade;
	bool is_signed;

public:
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade too high";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade too low";
		}
	};

	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw() {
			return "Form is not signed";
		}
	};

	AForm();
	AForm(const std::string &name, short int s_grade, short int e_grade);
	virtual ~AForm();
	AForm(const AForm &obj);
	AForm& operator=(const AForm &obj);
	
	bool getisSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	const std::string& getName() const;
	void beSigned(const Bureaucrat &bureaucrat);
	void execute(Bureaucrat const & executor) const;
	virtual void executeAction() const = 0;
	
protected:
	void CheckExecRights(const Bureaucrat &e) const;
};

std::ostream& operator<<(std::ostream &os, const AForm &f);

#endif