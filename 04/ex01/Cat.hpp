#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : virtual public Animal
{
private:
	Brain *b;
public:
	Cat();
	Cat(const std::string &catType);
	virtual ~Cat();
	Cat(const Cat &obj);
	Cat &operator=(const Cat &obj);
	virtual void makeSound() const;
};

#endif