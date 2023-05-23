/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:04:54 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:16:22 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
: __type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria (const AMateria &obj)
: __type(obj.getType())
{
}
AMateria& AMateria::operator=(const AMateria& x)
{
	this->__type = x.getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->__type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Materia of type \"" << this->__type << "\" has been used on " << target.getName() << "." << std::endl;
}
