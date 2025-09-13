#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"
class ScavTrap : protected ClapTrap
{	
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap& obj);
	ScavTrap& operator=(const ScavTrap& obj);
	ScavTrap(const std::string &name);
	virtual void attack(const std::string& target = DEFAULT_E);
	void guardGate();
};

#endif
