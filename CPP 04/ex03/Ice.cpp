/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:30:27 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:37:58 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"

Ice::Ice(/* args */)
:AMateria::AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice (const Ice &obj)
:AMateria::AMateria(obj)
{
}

Ice& Ice::operator=(const Ice& x)
{
	this->__type = x.getType();
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria * clone = new Ice(*this);
	return (clone);
}