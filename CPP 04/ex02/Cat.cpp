/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:43 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 13:20:07 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(/* args */)
: Animal::Animal("Cat")
{
	std::cout << "\e[1;34mCat created\e[0;m" << std::endl;
	this->brain = new Brain();
	for (size_t i = 0; i < 100; i++)
	{
		this->brain->SetIdeas(i, "Conquer the world");
	}
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "\e[0;31mCat deleted\e[0;m" << std::endl;
}

Cat::Cat (const Cat &obj)
: Animal::Animal(obj)
{
	std::cout << "\e[1;34mCat created\e[0;m" << std::endl;
	this->brain = new Brain();
	*this->brain = *obj.brain;
}

Cat& Cat::operator=(const Cat& obj)
{
	this->type = obj.getType();
	*this->brain = *obj.brain;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Yes, I am a cat! Did you really think I was going to meow? You're very stupid. We'll dominate the world ! And Oh ! A ball of wool ! MEOW !" << std::endl;
}

void	Cat::PrintIdeas() const
{
	std::cout << this->type << " ";
	this->brain->PrintIdeas();
}

void	Cat::SetIdeas(unsigned int ind, std::string ideas)
{
	this->brain->SetIdeas(ind, ideas);
}