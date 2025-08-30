#include "Zombie.hpp"

int main()
{
	Zombie *kek = newZombie("AllocZombie");
	randomChump("Chump1");
	randomChump("Chump2");
	kek->announce();
	delete kek;
}