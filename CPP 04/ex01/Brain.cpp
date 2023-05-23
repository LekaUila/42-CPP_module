/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:33:18 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 13:27:36 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(/* args */)
{
	std::cout << "\e[1;34mHe has a Brain !\e[0;m" << std::endl;
}

Brain::~Brain()
{
	std::cout << "\e[0;31mThe Brain is off because of a 404 error...\e[0;m" << std::endl;
}

Brain::Brain (const Brain &obj)
{
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = obj.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& obj)
{
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

void	Brain::PrintIdeas() const
{
	std::cout << "Ideas :" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "- "<< this->ideas[i] << std::endl;
	}
}

void	Brain::SetIdeas(unsigned int ind, std::string ideas)
{
	if (ind < 100)
	{
		this->ideas[ind] = ideas;
	}
}