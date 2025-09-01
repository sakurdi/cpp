#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook kek;
	std::string input;

	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;

	while (1)
	{
		std::cout << "Enter command: ";
		if (!(std::cin >> input))
		{
			if (std::cin.eof())
			{
					std::cout << "\nEOF recieved, exiting." << std::endl;
					break;
			}
			else
				std::cout << "\nInput error." << std::endl;
			break; 
		}
		if (input.compare("ADD") == 0)
		{
			if (!kek.addContact())
			{
				std::cout << "\nEOF received, exiting." << std::endl;
				break;
			}
		}
		else if (input.compare("SEARCH") == 0)
			kek.searchContact();
		else if (input.compare("EXIT") == 0)
			break;
		else
			std::cout << "Invalid command! Type \"ADD\" to add a contact, \"SEARCH\" to view contacts, or \"EXIT\" to exit the program" << std::endl;
	}
	return 0;
}
