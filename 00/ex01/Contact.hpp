#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact {
	
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string darkest_secret;
	std::string phone_number;
	
	public:
		Contact();
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		void getContacts();
		void setContact(const std::string &fname, const std::string &lname,
						const std::string &nick, const std::string &phone,
						const std::string &secret);
};
#endif