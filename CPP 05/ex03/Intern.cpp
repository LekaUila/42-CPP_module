/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:33:47 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/01 18:54:07 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}

Intern::Intern (const Intern &obj)
{
	(void) obj;
}
Intern& Intern::operator=(const Intern& x)
{
	(void) x;
	return (*this);
}

Form *Intern::makeForm(std::string form, std::string target) const
{
	std::string tab_s[4];
	int			i;
	Form *new_form = 0;

	tab_s[0] = "robotomy request";
	tab_s[1] = "presidential pardon";
	tab_s[2] = "shrubbery creation";
	i = 0;
	while (i != 4)
	{
		if (tab_s[i] == form)
		{
			switch (i)
			{
			case 0: 
				new_form = new RobotomyRequestForm(target);
				break;
			case 1:
				new_form = new PresidentialPardonForm(target);
				break;                              
			case 2:
				new_form = new ShrubberyCreationForm(target);
				break;
			}
			std::cout << "Intern creates " << form << "." << std::endl;
			return (new_form);
		}
		i++;
	}
	std::cout << "Intern is not smart enough to create " << form << "." << std::endl;
	return (0);
}
