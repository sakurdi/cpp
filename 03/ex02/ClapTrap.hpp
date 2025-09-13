#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define DEFAULT_E "default PNJ"

class ClapTrap
{
protected:
	std::string name;
	int hit_points;
	int energy_points;
	int attack_damage;

public:
	ClapTrap();
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap &obj);
	ClapTrap(const std::string &name);
	ClapTrap &operator=(const ClapTrap &obj);
	virtual void attack(const std::string &target = DEFAULT_E);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	const std::string getName(void) const;
	int getHP(void) const;
	int getEP(void) const;
	int getAP(void) const;
};

#endif
