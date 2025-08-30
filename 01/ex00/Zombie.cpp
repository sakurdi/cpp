#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
}
Zombie::~Zombie()
{
	std::cout << this->name << " retourne à la terre" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
