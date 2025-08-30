#include "Zombie.hpp"

int main()
{
	Zombie *ptr = zombieHorde(5, "CUCK");
	for(size_t i = 0; i < 5; i++)
		ptr[i].announce();
	delete[] ptr;
}