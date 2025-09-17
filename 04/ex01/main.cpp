#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
int main()
{
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog("Dog");
	// const Animal* i = new Cat("Cat");
	

	// std::cout << "-------GOOD POLYMORPHISM DISPLAY-------" << std::endl;
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound();
	// j->makeSound();
	// meta->makeSound();
	// std::cout << "-------GOOD POLYMORPHISM DISPLAY-------" << std::endl;

	// std::cout << "-------BAD POLYMORPHISM DISPLAY-------" << std::endl;
	// const WrongAnimal *wa = new WrongAnimal();
	// const WrongAnimal *wc = new WrongCat();
	// wa->makeSound();
	// wc->makeSound();
	// std::cout << "-------BAD POLYMORPHISM DISPLAY-------" << std::endl;


	// delete meta, delete j, delete i;
	// delete wa, delete wc;
	Animal *animalArr = new Animal[10];
	for(size_t i = 0; i < 10; i++)
	{
		if(i % 2 == 0)
			animalArr[i] = Cat();
		else
			animalArr[i] = Dog();
	}
	// Brain *b = new Brain();
	// delete(b);
	delete[] animalArr;
	return 0;
}