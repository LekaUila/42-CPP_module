/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:46 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 13:20:54 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(/* args */)
: Animal::Animal("Dog")
{
	std::cout << "\e[1;34mDog created\e[0;m" << std::endl;
	this->brain = new Brain();
	for (size_t i = 0; i < 100; i++)
	{
		this->brain->SetIdeas(i, "Nonos");
	}
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "\e[0;31mDog deleted\e[0;m" << std::endl;
}

Dog::Dog (const Dog &obj)
: Animal::Animal(obj)
{
	std::cout << "\e[1;34mDog created\e[0;m" << std::endl;
	this->brain = new Brain();
	*this->brain = *obj.brain;
}

Dog& Dog::operator=(const Dog& obj)
{
	this->type = obj.getType();
	*this->brain = *obj.brain;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wouaf !" << std::endl;
}

void	Dog::PrintIdeas() const
{
	std::cout << this->type << " ";
	this->brain->PrintIdeas();
}

void	Dog::SetIdeas(unsigned int ind, std::string ideas)
{
	this->brain->SetIdeas(ind, ideas);
}