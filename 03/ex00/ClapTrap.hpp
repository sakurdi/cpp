#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    std::string name;
    int hit_points;
    int energy_points;
    int attack_damage;

    public:
    ClapTrap();
    ~ClapTrap();
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif 
