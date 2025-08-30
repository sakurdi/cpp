#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
}
Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
	void Zombie::set_zombie_name(std::string name)
	{
		this->name = name;
	}
 