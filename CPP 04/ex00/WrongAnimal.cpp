/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:39 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/23 11:40:05 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "\e[1;34mWrongAnimal created\e[0;m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string t)
: type(t)
{
	std::cout << "\e[1;34mWrongAnimal created\e[0;m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mWrongAnimal deleted\e[0;m" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal &obj)
: type(obj.getType())
{
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	this->type = obj.getType();
	return (*this);
}


std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal song" << std::endl;
}