
#include "FragTrap.hpp"

FragTrap::FragTrap()
:ClapTrap::ClapTrap("FragTrap", 100, 100, 30)
{
	std::cout <<  this->get_name() << "'s \e[1;34mfists\e[0;m are hot as embers." << std::endl;
}

FragTrap::FragTrap(std::string name)
:ClapTrap::ClapTrap(name, 100, 100, 30)
{
	std::cout <<  this->get_name() << "'s \e[1;34mfists\e[0;m are hot as embers." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << this->get_name() << "'s \e[1;34mfists\e[0;m are now cold as ice." << std::endl;
}

FragTrap::FragTrap (const FragTrap &obj)
: ClapTrap::ClapTrap(obj)
{
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	std::cout << this->__Name << " is now named " << obj.get_name() << "." << std::endl;
	this->__Name = obj.get_name();
	this->__Energy_points = obj.get_ep();
	this->__Hit_Points = obj.get_hp();
	this->__Attack_Damage = obj.get_atk();
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "\e[0;32mHigh Fives Guys ?\e[0;m" << std::endl;
}

