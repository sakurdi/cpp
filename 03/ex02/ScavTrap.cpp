#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("PNJ")
{
	this->attack_damage = 20;
	this->energy_points = 50;
	this->hit_points = 100;
	std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->attack_damage = 20;
	this->energy_points = 50;
	this->hit_points = 100;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(target == "Default")
		std::cout << "ScavTrap " << this->name << " attacks default enemy, causing " << this->attack_damage << " points of damage!" << std::endl; 
	else
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl; 
}

void ScavTrap::guardGate()
{
	std::cout << "Scavtrap " << this->name << " guards the gate!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &obj)
		ClapTrap::operator=(obj);
	return *this;
}
