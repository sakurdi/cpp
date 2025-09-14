#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	virtual ~DiamondTrap();
	DiamondTrap(const DiamondTrap& obj);
	DiamondTrap& operator=(const DiamondTrap& obj);
	using ScavTrap::attack;
	void whoAmI();
	virtual void attack(const std::string& target = DEFAULT_E);


};



#endif