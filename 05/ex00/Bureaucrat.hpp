#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define default_name "Wagie"

class Bureaucrat : public std::exception
{
private:
	const std::string name;
	short int grade;
public:
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(const std::string &name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &obj);
	void incGrade();
	void decGrade();

	Bureaucrat& operator=(const Bureaucrat &obj);
	short int getGrade() const;
	const std::string &getName() const;
};



#endif