
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
:ClapTrap::ClapTrap("ScavTrap", 100, 50, 20)
{
	std::cout << "The \e[0;33mshield\e[0;m of " << this->get_name() << " is ready." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
:ClapTrap::ClapTrap(name, 100, 50, 20)
{
	std::cout << "The \e[0;33mshield\e[0;m of " << this->get_name() << " is ready." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "The \e[0;33mshield\e[0;m of " << this->get_name() << " is break." << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap &obj)
: ClapTrap::ClapTrap(obj)
{
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << this->__Name << " is now named " << obj.get_name() << "." << std::endl;
	this->__Name = obj.get_name();
	this->__Energy_points = obj.get_ep();
	this->__Hit_Points = obj.get_hp();
	this->__Attack_Damage = obj.get_atk();
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << this->__Name << " is now in \e[0;33mGKM (Gate Keeper Mode)\e[0;m." << std::endl;
}
