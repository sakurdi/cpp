#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default") 
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) 
{
    std::cout << "ClapTrap name set to :" << name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
   *this = obj; 
}

ClapTrap::ClapTrap &operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap assignation constructor called" << std::endl;
    if(this != other)
    {
        this->name = obj.name;
        this->hit_points = obj.hit_points;
        this->energy_points = obj.energy_points;
        this->attack_damage = obj.attack_damage;
    }
}

void ClapTrap::attack(const std::string &target)
{
    
}
