#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
int main()
{
	DiamondTrap diamond("StackDiamond");
	diamond.attack("Bad person");
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();

	DiamondTrap copy(diamond);
	copy.whoAmI();

	DiamondTrap assigned("AssignedStackDiamond");
	assigned = diamond;
	assigned.whoAmI();

	ClapTrap *p1 = new DiamondTrap("Diamond1");
	FragTrap *p2 = new DiamondTrap("Diamond2");
	ScavTrap *p3 = new DiamondTrap("Diamond3");
	p1->attack("MauvaisePersonne1");
	p2->attack("MauvaisePersonne2");
	p3->attack("MauvaisePersonne3");
	delete p1;
	delete p2;
	delete p3;
}


