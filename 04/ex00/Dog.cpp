#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const std::string &DogType) : Animal(DogType)
{
	std::cout << "Dog parameterized constructor called with type: " << DogType << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &obj)
		Dog::operator=(obj);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog class base destructor Called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->getType() << " is WOOFING" << std::endl;
}

