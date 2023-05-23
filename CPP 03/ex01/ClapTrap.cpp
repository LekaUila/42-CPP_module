/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:02:53 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/19 13:41:35 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: __Name("ClapTrap"), __Hit_Points(10), __Energy_points(10), __Attack_Damage(0)
{
	std::cout << this->__Name << " has join the game." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: __Name(name), __Hit_Points(10), __Energy_points(10), __Attack_Damage(0)
{
	std::cout << this->__Name << " has join the game." << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int atk)
: __Name(name), __Hit_Points(hp), __Energy_points(ep), __Attack_Damage(atk)
{
	std::cout << this->__Name << " has join the game." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->__Name << " has left the game." << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &obj)
: __Name(obj.get_name()), __Hit_Points(obj.get_hp()), __Energy_points(obj.get_ep()), __Attack_Damage(obj.get_atk())
{
	std::cout << "A new " << this->__Name << " has Join the game." << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << this->__Name << " is now named " << obj.get_name() << "." << std::endl;
	this->__Name = obj.get_name();
	this->__Energy_points = obj.get_ep();
	this->__Hit_Points = obj.get_hp();
	this->__Attack_Damage = obj.get_atk();
	return (*this);
}


void ClapTrap::attack(const std::string& target)
{
	if (this->__Energy_points > 0)
	{
		std::cout << this->__Name << " attack " << target << ". It has lose " << this->__Attack_Damage << " \e[0;31mHit(s) Point(s)\e[0;m." << std::endl;
		this->__Energy_points--;
	}
	else
		std::cout << this->__Name << " is out of energy." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int	new_life;

	if (this->__Hit_Points == 0)
	{
		std::cout << this->__Name << " is already dead." << std::endl;
		return ;
	}
	new_life = this->__Hit_Points - amount;
	if (new_life < 0)
	{
		new_life = 0;
	}
	this->__Hit_Points = new_life;
	if (new_life)
	{
		std::cout << this->__Name << " has lose " << amount << " \e[0;31mHit(s) Point(s)\e[0;m. It has now " << new_life << " \e[0;31mHit(s) Point(s)\e[0;m." << std::endl;
		return ;
	}
	std::cout << this->__Name << " has lose " << amount << " \e[0;31mHit(s) Point(s)\e[0;m. It is now dead." << std::endl;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->__Energy_points > 0)
	{
		std::cout << this->__Name  << " it's fixed successfully. It has win  " << amount << " \e[0;31mHit(s) Point(s)\e[0;m." << std::endl;
		this->__Energy_points--;
		this->__Hit_Points += amount;
	}
	else
		std::cout << this->__Name << " is out of energy." << std::endl;
}
std::string ClapTrap::get_name() const
{
	return (this->__Name);
}

int ClapTrap::get_hp() const
{
	return(this->__Hit_Points);
}
int ClapTrap::get_ep() const
{
	return(this->__Energy_points);
}
int ClapTrap::get_atk() const
{
	return(this->__Attack_Damage);
}
/*
void ClapTrap::set_name(std::string name)
{
	this->__Name = name;
}
void ClapTrap::set_hp(int hp)
{
	this->__Hit_Points = hp;
}
void ClapTrap::set_ep(int ep)
{
	this->__Energy_points = ep;
}
void ClapTrap::set_atk(int atk)
{
	this->__Attack_Damage = atk;
}*/