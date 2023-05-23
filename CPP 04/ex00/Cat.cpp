/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:43 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 13:20:51 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat(/* args */)
: Animal::Animal("Cat")
{
	std::cout << "\e[1;34mCat created\e[0;m" << std::endl;
}

Cat::~Cat()
{
	std::cout << "\e[0;31mCat deleted\e[0;m" << std::endl;
}

Cat::Cat (const Cat &obj)
: Animal::Animal(obj)
{
	std::cout << "\e[1;34mCat created\e[0;m" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	this->type = obj.getType();
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Yes, I am a cat! Did you really think I was going to meow? You're very stupid. We'll dominate the world ! And Oh ! A ball of wool ! MEOW !" << std::endl;
}