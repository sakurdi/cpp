#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
	std::string name;
	Weapon *weapon;

	public:
	HumanB(const std::string &name);
	void setWeapon(Weapon &weapon);
	void attack();

};

#endif