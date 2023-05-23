/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:43 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/23 11:37:25 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */)
: WrongAnimal::WrongAnimal("WrongCat")
{
	std::cout << "\e[1;34mWrongCat created\e[0;m" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mWrongCat deleted\e[0;m" << std::endl;
}

WrongCat::WrongCat (const WrongCat &obj)
: WrongAnimal::WrongAnimal(obj)
{
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	this->type = obj.getType();
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong cat song" << std::endl;
}
