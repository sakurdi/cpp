#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	std::string name;

	public:
	Zombie();
	Zombie(std::string name);
	void announce( void );
	void set_zombie_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif