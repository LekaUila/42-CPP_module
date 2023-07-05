/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:08:48 by lflandri          #+#    #+#             */
/*   Updated: 2023/07/05 11:26:50 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



Zombie::Zombie()
:	name("not named")
{
	std::cout << "\e[1;37mZombie\"\e[0;32m" << this->name
	<< "\e[1;37m\" has been summon by the \e[0;35mdarness\e[1;37m.\e[0;m"
	<< std::endl;
}

Zombie::Zombie(std::string name)
:	name(name)
{
	std::cout << "\e[1;37mZombie\"\e[0;32m" << this->name
	<< "\e[1;37m\" has been summon by the \e[0;35mdarness\e[1;37m.\e[0;m"
	<< std::endl;
}

Zombie::~Zombie()
{
	std::cout << "\e[1;37mZombie \"\e[0;32m" << this->name
	<< "\e[1;37m\" has been \e[0;31mkilled\e[1;37m by the \e[1;33msun\e[1;37m.\e[0;m"
	<< std::endl;
}

void Zombie::announce( void )
{
	std::cout << "\e[1;32m" << name << "\e[0;m: BraiiiiiiinnnzzzZ...."
	<< std::endl;
}

void Zombie::setname(std::string name)
{
	std::cout << "\e[1;37mZombie\"\e[0;32m" << this->name
	<< "\e[1;37m\" has been rename with \"\e[0;32m" << name
	<< "\e[1;37m\".\e[0;m"
	<< std::endl;
	this->name = name;
}

Zombie* newZombie( std::string name )
{
	Zombie *zombzomb = new Zombie(name);
	return zombzomb;
}

void randomChump( std::string name )
{
	Zombie	zombzomb(name);
	zombzomb.announce();
}
