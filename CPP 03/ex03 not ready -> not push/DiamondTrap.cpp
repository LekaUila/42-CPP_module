
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
:ScavTrap::ScavTrap("DiamondTrap")
{
	std::cout << "The \e[0;33mshield\e[0;m of " << this->get_name() << " is ready." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
:ScavTrap::ScavTrap(name)
{
	std::cout << "The \e[0;33mshield\e[0;m of " << this->get_name() << " is ready." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "The \e[0;33mshield\e[0;m of " << this->get_name() << " is break." << std::endl;
}

DiamondTrap::DiamondTrap (const DiamondTrap &obj)
:ScavTrap::ScavTrap(obj)
{
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	std::cout << this->__Name << " is now named " << obj.get_name() << "." << std::endl;
	this->__Name = obj.get_name();
	this->__Energy_points = obj.get_ep();
	this->__Hit_Points = obj.get_hp();
	this->__Attack_Damage = obj.get_atk();
	return (*this);
}


void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	ScavTrap::takeDamage(amount);	
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	ScavTrap::beRepaired(amount);
}
std::string DiamondTrap::get_name() const
{
	return (ScavTrap::get_name());
}

int DiamondTrap::get_hp() const
{
	return(ScavTrap::get_hp());
}
int DiamondTrap::get_ep() const
{
	return(ScavTrap::get_ep());
}
int DiamondTrap::get_atk() const
{
	return(ScavTrap::get_atk());
}