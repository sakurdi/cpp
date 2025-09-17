#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string &catType) : WrongAnimal(catType)
{
	std::cout << "WrongCat parameterized constructor called with type: " << catType << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &obj)
		WrongAnimal::operator=(obj);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongACat destructor called for type: " << type << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat WrongMeow" << std::endl;
}
