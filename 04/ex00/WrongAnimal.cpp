#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &animalType) : type(animalType)
{
	std::cout << "WrongAnimal name constructor called for type : " << animalType << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) : type(obj.type)
{
	std::cout << "WrongAnimal copy constructor called for type: " << this->type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called for type: " << type << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal noise" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
