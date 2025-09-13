#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Personne"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap name constructor called and set to : " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	*this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "ClapTrap assignation constructor called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hit_points = obj.hit_points;
		this->energy_points = obj.energy_points;
		this->attack_damage = obj.attack_damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if(target == "Default")
		std::cout << "ClapTrap " << this->name << " attacks default enemy dealing " << this->attack_damage << " points of damage!" << std::endl; 
	else
		std::cout << "ClapTrap " << this->name << " attacks " << target << " dealing " << this->attack_damage << " points of damage!" << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(amount == 0)
		std::cout << "ClapTrap " << this->name << " takes no damage" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " takes " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " regains HP: " << amount << std::endl;
}
