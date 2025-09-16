#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &animalType) : type(animalType)
{
	std::cout << "Animal name constructor called for type : " << animalType << std::endl;
}

Animal::Animal(const Animal &obj) : type(obj.type)
{
	std::cout << "Animal copy constructor called for type: " << this->type << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called for type: " << type << std::endl;
}

const std::string &Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << this->getType() << " is METASCREAMING" << std::endl;
}
