#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called for " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
	: AForm(obj), target(obj.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
	{
		AForm::operator=(obj);
		this->target = obj.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename = this->target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: Could not create " << filename << std::endl;
		return;
	}

	file << " ,d                                      \n";
	file << "  88                                      \n";
	file << "MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  \n";
	file << "  88    88P'   \"Y8 a8P_____88 a8P_____88  \n";
	file << "  88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"  \n";
	file << "  88,   88         \"8b,   ,aa \"8b,   ,aa  \n";
	file << "  \"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"'   \n";

	file.close();
	std::cout << "Tree planted at " << this->target << std::endl;
}