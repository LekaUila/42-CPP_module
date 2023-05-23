/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:28:23 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 15:26:24 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
: type(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::gettype(void) const
{
	/*const std::string &ref = this->type;
	return (ref); */
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}