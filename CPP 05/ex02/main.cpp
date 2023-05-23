/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:53:34 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/01 18:10:55 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main(void)
{
	Bureaucrat chuck("Chuck Norris", 1);
	Form *lol = new PresidentialPardonForm("Bart");
	Form *brainfuck = new RobotomyRequestForm("Bart");
	Form *tree = new ShrubberyCreationForm("garden");
	chuck.signForm(*lol);
	chuck.signForm(*brainfuck);
	chuck.signForm(*tree);
	chuck.executeForm(*lol);
	chuck.executeForm(*brainfuck);
	chuck.executeForm(*tree);

	RobotomyRequestForm not_for_baka("Homert");
	Bureaucrat baka("A stupid Random people", 150);


	try
	{
		baka.signForm(not_for_baka);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		chuck.executeForm(not_for_baka);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	chuck.signForm(not_for_baka);
	try
	{
		baka.executeForm(not_for_baka);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete lol;
	delete brainfuck;
	delete tree;
	return (0);
}