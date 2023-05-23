/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:34:40 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:39:00 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

MateriaSource::MateriaSource(/* args */)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->__inventory[i] = 0;
	}
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->__inventory[i] != 0)
			delete this->__inventory[i];
	}
}

MateriaSource::MateriaSource (const MateriaSource &obj)
: IMateriaSource::IMateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		const AMateria * materia = obj.getinventorytoind(i);
		if (materia != 0)
			this->__inventory[i] = materia->clone();
		else
			this->__inventory[i] = 0;
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource& x)
{
	for (size_t i = 0; i < 4; i++)
	{
		const AMateria * materia = x.getinventorytoind(i);
		if (materia != 0)
			this->__inventory[i] = materia->clone();
		else
			this->__inventory[i] = 0;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->__inventory[i] == 0)
		{
			this->__inventory[i] = m;
			return ;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		
		if (this->__inventory[i] != 0)
		{
			if (this->__inventory[i]->getType() == type)
				return (this->__inventory[i]->clone());
		}
	}
	return (0);
}

const AMateria * MateriaSource::getinventorytoind(int ind) const
{
	if (ind < 4 && ind > -1)
		return (this->__inventory[ind]);
	return (0);
}