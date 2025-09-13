#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : protected ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &obj);
	~FragTrap();
	FragTrap &operator=(const FragTrap &obj);
	virtual void attack(const std::string &target = DEFAULT_E);
	void highFivesGuys(void);
};

#endif
