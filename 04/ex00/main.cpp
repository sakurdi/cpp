#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	

	std::cout << "-------GOOD POLYMORPHISM DISPLAY-------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "-------GOOD POLYMORPHISM DISPLAY-------" << std::endl;

	std::cout << "-------BAD POLYMORPHISM DISPLAY-------" << std::endl;
	const WrongAnimal *wa = new WrongAnimal();
	const WrongAnimal *wc = new WrongCat();
	wa->makeSound();
	wc->makeSound();
	std::cout << "-------BAD POLYMORPHISM DISPLAY-------" << std::endl;


	delete meta; delete j; delete i;
	delete wa; delete wc;
	return 0;
}