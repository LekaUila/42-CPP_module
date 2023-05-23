/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:30:05 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 15:04:20 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"

Character::Character(std::string const name)
: __name(name)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->__inventory[i] = 0;
	}
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->__inventory[i] != 0)
			delete this->__inventory[i];
	}
}

Character::Character (const Character &obj)
: ICharacter::ICharacter(), __name(obj.getName())
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
Character& Character::operator=(const Character& x)
{
	this->__name = x.getName();
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

std::string const & Character::getName() const
{
	return (this->__name);
}
void Character::equip(AMateria* m)
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
void Character::unequip(int idx)
{
	if (idx < 4 && idx > -1)
		this->__inventory[idx] = 0;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx > -1)
	{
		if (this->__inventory[idx] != 0)
			this->__inventory[idx]->use(target);
	}
}

const AMateria * Character::getinventorytoind(int ind) const
{
	if (ind < 4 && ind > -1)
		return (this->__inventory[ind]);
	return (0);
}