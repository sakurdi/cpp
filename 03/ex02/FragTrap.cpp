#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFrag")
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &obj)
		ClapTrap::operator=(obj);
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << this->name << " attacks " << target<< " dealing " << this->attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " humbly demands a high five" << std::endl;
}
