#include "Cat.hpp"

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	this->b = new Brain();
}

Cat::Cat(const std::string &catType) : Animal(catType)
{
	this->b = new Brain();
	std::cout << "Cat parameterized constructor called with type: " << catType << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	this->b = new Brain(*obj.b);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &obj)
	{
		Animal::operator=(obj);
		delete this->b;
		this->b = new Brain(*obj.b);
	}
	return *this;
}

Cat::~Cat()
{
	delete this->b;
	std::cout << "Cat class base destructor Called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << this->getType() << " is MEOWING" << std::endl;
}

