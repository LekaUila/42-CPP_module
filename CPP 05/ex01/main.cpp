/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:53:34 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/01 12:34:23 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{

	try
	{
		Form test("lol", 15, 210);
		std::cout << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form test("lol", -1, 86);
		std::cout << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Form test("Projet de création d'usine à cosplay pour weeb", 15, 86);
	std::cout << test << std::endl;
	Bureaucrat jk("Jean-Kevin", 42);
	Bureaucrat boss("Obama", 1);
	std::cout << jk << std::endl;
	std::cout << boss << std::endl;

	jk.signForm(test);
	boss.signForm(test);
	return (0);
}