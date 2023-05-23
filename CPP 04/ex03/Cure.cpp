/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:30:18 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:37:43 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"

Cure::Cure()
:AMateria::AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure (const Cure &obj)
:AMateria::AMateria(obj)
{
}
Cure& Cure::operator=(const Cure& x)
{
	this->__type = x.getType();
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria * clone = new Cure(*this);
	return (clone);
}