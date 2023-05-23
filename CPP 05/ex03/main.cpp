/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:53:34 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/01 18:58:58 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main(void)
{
	Intern coffee_station;
	Bureaucrat chuck("Chuck Norris", 1);
	Form *lol = coffee_station.makeForm("presidential pardon", "Bart");
	Form *brainfuck = coffee_station.makeForm("robotomy request", "Bart");
	Form *tree = coffee_station.makeForm("shrubbery creation", "Bart");
	Form *hello = coffee_station.makeForm("Hello World !", "Bart");
	(void) hello;
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