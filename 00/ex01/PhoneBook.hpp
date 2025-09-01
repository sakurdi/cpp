#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <cctype>
#include <iostream>
#include <istream>
#include <limits.h>
class PhoneBook {
	Contact contacts[8];
	size_t contact_index;
	size_t total_contacts;
	int is_only_whitespace(std::string str);
	int letters_only(std::string str);
	int validate_number(std::string str);
	std::string truncate_string(std::string str);
public:
	PhoneBook();
	bool addContact();
	void searchContact();
};
#endif
