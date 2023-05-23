/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:00:53 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 15:31:54 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
:	weapon(&weapon),
	name(name)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << "\e[0;33m" << this->name <<
	"\e[1;37m attacks with their \e[0;36m" <<
	this->weapon->gettype() << "\e[0;m" << std::endl;
}