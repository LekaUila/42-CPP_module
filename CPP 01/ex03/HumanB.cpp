/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:32:36 by lflandri          #+#    #+#             */
/*   Updated: 2023/06/23 14:53:19 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
:	weapon(NULL),
	name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (this->weapon)
	{
		std::cout << "\e[0;33m" << this->name <<
		"\e[1;37m attacks with their \e[0;36m" <<
		this->weapon->gettype() << "\e[0;m" << std::endl;
	}

}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}