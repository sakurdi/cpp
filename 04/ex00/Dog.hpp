#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : virtual public Animal
{
private:
public:
	Dog();
	Dog(const std::string &dogType);
	Dog(const Dog &obj);
	Dog &operator=(const Dog &obj);
	virtual ~Dog();
	virtual void makeSound() const;
};

#endif