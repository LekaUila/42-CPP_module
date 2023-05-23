/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:46 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 13:20:30 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(/* args */)
: Animal::Animal("Dog")
{
	std::cout << "\e[1;34mDog created\e[0;m" << std::endl;
}

Dog::~Dog()
{
	std::cout << "\e[0;31mDog deleted\e[0;m" << std::endl;
}

Dog::Dog (const Dog &obj)
: Animal::Animal(obj)
{
	std::cout << "\e[1;34mDog created\e[0;m" << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	this->type = obj.getType();
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouaf !" << std::endl;
}