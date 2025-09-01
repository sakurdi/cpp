#include "Contact.hpp"


Contact::Contact()
{
}

std::string Contact::getFirstName() const
{
	return first_name;
}

std::string Contact::getLastName() const
{
	return last_name;
}

std::string Contact::getNickname() const
{
	return nick_name;
}

std::string Contact::getPhoneNumber() const
{
	return phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return darkest_secret;
}

void Contact::setContact(const std::string &fname, const std::string &lname,
						 const std::string &nick, const std::string &phone,
						 const std::string &secret)
{
	this->first_name = fname;
	this->last_name = lname;
	this->nick_name = nick;
	this->phone_number = phone;
	this->darkest_secret = secret;
}
