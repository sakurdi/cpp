#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_index = 0;
	this->total_contacts = 0;
}

int PhoneBook::is_only_whitespace(std::string str)
{
	if (str.empty())
		return 1;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isspace(str[i]))
			return 0;
	}
	std::cout << "Field cannot be only whitespace!" << std::endl;
	return 1;
}

int PhoneBook::letters_only(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]) && !isspace(str[i]) && str[i] != '-')
		{
			std::cout << "First name, Last name and Nickname must only have letters, spaces, and hyphens" << std::endl;
			return 0;
		}
	}
	return 1;
}

int PhoneBook::validate_number(std::string str)
{
	int plus_count = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '+')
		{
			plus_count++;
			if (plus_count > 1 || i != 0)
			{
				std::cout << "Phone number can have only one '+' at the beginning" << std::endl;
				return 0;
			}
		}
		else if (!isdigit(str[i]) && !isspace(str[i]) && str[i] != '-')
		{
			std::cout << "Phone number must only contain digits, spaces, hyphens, and one '+' (at the beginning only)" << std::endl;
			return 0;
		}
	}
	return 1;
}

std::string PhoneBook::truncate_string(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

bool PhoneBook::addContact()
{
	std::string firstName, lastName, phoneNumber, nickname, darkestSecret;

	std::cout << "Press enter after typing your desired input for each required field." << std::endl;

	std::cout << "First name: ";
	std::cin.ignore();
	if (!std::getline(std::cin, firstName))
		return false;

	std::cout << "Last name: ";
	if (!std::getline(std::cin, lastName))
		return false;

	std::cout << "Nickname: ";
	if (!std::getline(std::cin, nickname))
		return false;

	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, darkestSecret))
		return false;

	std::cout << "Phone number: ";
	if (!std::getline(std::cin, phoneNumber))
		return false;

	if (firstName.empty() || lastName.empty() || phoneNumber.empty() ||
		nickname.empty() || darkestSecret.empty() ||
		is_only_whitespace(firstName) || is_only_whitespace(lastName) ||
		is_only_whitespace(nickname) || is_only_whitespace(darkestSecret) ||
		is_only_whitespace(phoneNumber) ||
		!letters_only(firstName) || !letters_only(lastName) || !letters_only(nickname) ||
		!validate_number(phoneNumber))
	{
		std::cout << "Invalid input, Contact not added to the contact list." << std::endl;
		return 1;
	}

	if (contact_index >= 8)
		contact_index = 0;

	contacts[contact_index].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	contact_index++;

	if (total_contacts < 8)
		total_contacts++;

	std::cout << "Contact added to the Phone Book" << std::endl;
	return 1;
}

void PhoneBook::searchContact()
{
	if (this->total_contacts == 0)
	{
		std::cout << "No existing contacts, please add one executing the \"ADD\" command" << std::endl;
		return ;
	}

	std::cout << std::setw(10) << std::right << "Index " << "|"
			  << std::setw(10) << std::right << "First Name " << "|"
			  << std::setw(10) << std::right << "Last Name" << "|"
			  << std::setw(10) << std::right << "Nickname" << std::endl;
	std::cout << std::string(43, '-') << std::endl;

	for (size_t i = 0; i < total_contacts; i++)
	{
		std::cout << std::setw(10) << std::right << i + 1 << "|"
				  << std::setw(10) << std::right << truncate_string(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << std::right << truncate_string(contacts[i].getLastName()) << "|"
				  << std::setw(10) << std::right << truncate_string(contacts[i].getNickname()) << std::endl;
	}

	std::cout << "\nEnter index to view full contact details: ";
	size_t index = 0;
//	std::cin >> index;
//	std::cin.clear();
	if (!(std::cin >> index) || index > total_contacts || index == 0)
	{
		std::cout << "Invalid index" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return ;
	}
	index--;
	std::cout << "\n--- Contact Details ---" << std::endl;
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
