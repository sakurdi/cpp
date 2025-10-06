#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "***** VALID FORMS *****" << std::endl;
	{
		Intern squire;
		AForm* quest;
		
		quest = squire.createForm("RobotomyRequest", "Azure Drake");
		if (quest)
		{
			std::cout << *quest << std::endl;
			delete quest;
		}
	}

	std::cout << "\n***** ALL FORMS *****" << std::endl;
	{
		Intern apprentice;
		
		AForm* forest = apprentice.createForm("ShrubberyCreation", "Enchanted Forest");
		AForm* golem = apprentice.createForm("RobotomyRequest", "Iron Golem");
		AForm* mercy = apprentice.createForm("PresidentialPardon", "Holy Paladin");
		
		if (forest)
		{
			std::cout << *forest << std::endl;
			delete forest;
		}
		if (golem)
		{
			std::cout << *golem << std::endl;
			delete golem;
		}
		if (mercy)
		{
			std::cout << *mercy << std::endl;
			delete mercy;
		}
	}

	std::cout << "\n***** INVALID FORM NAME *****" << std::endl;
	{
		Intern scribe;
		AForm* scroll;
		
		scroll = scribe.createForm("Ice Bolt", "Goblin");
		if (scroll == NULL)
			std::cout << "form is invalid (expected behavior)" << std::endl;
	}

	std::cout << "\n***** EXTRA *****" << std::endl;
	{
		Intern servant;
		Bureaucrat wizard("Gandalf", 1);
		
		AForm* pardon = servant.createForm("Smug Smaug", "Sauron");
		if (pardon)
		{
			std::cout << *pardon << std::endl;
			wizard.signForm(*pardon);
			wizard.executeForm(*pardon);
			delete pardon;
		}
	}
}