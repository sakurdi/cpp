#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <typeinfo>
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const std::string &animalType);
	Animal(const Animal &obj);
	Animal &operator=(const Animal &obj);
	virtual ~Animal();
	virtual void makeSound() const;
	const std::string &getType() const;
};


#endif