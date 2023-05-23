/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:31:53 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:36:30 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ICharacter.hpp"

ICharacter::ICharacter(/* args */)
{
}

ICharacter::~ICharacter()
{
}

ICharacter::ICharacter (const ICharacter &obj)
{
	(void) obj;
}
ICharacter& ICharacter::operator=(const ICharacter& x)
{
	(void) x;
	return (*this);
}
