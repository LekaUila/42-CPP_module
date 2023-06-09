/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:08:48 by lflandri          #+#    #+#             */
/*   Updated: 2023/07/05 11:22:21 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"





Zombie::Zombie(std::string name)
:	name(name)
{
	std::cout << "Zombie \"" << this->name
	<< "\" has been summun by the darness."
	<< std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie \"" << this->name
	<< "\" has been killed by the sun."
	<< std::endl;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...."
	<< std::endl;
}
