#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"),
							 ScavTrap(),
							 FragTrap(),
							 name("Default")
{
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"),
													ScavTrap(name),
													FragTrap(name),
													name(name)
{
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj),
												   ScavTrap(obj),
												   FragTrap(obj),
												   name(obj.name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &obj)
	{
		ClapTrap::operator=(obj);
		FragTrap::operator=(obj);
		ScavTrap::operator=(obj);
		this->name = obj.name;
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "TADA! I happen to be... " << this->name << " , ClapTrap name -> " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
