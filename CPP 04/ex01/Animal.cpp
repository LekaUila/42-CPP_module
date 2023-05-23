/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:39 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 13:23:00 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "\e[1;34mAnimal created\e[0;m" << std::endl;
}

Animal::Animal(std::string t)
: type(t)
{
	std::cout << "\e[1;34mAnimal created\e[0;m" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\e[0;31mAnimal deleted\e[0;m" << std::endl;
}

Animal::Animal (const Animal &obj)
: type(obj.getType())
{
	std::cout << "\e[1;34mAnimal created\e[0;m" << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	this->type = obj.getType();
	return (*this);
}


std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Amimal song" << std::endl;
}