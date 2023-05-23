/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:12:57 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/07 16:38:23 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.hpp"


Base * generate(void)
{

	
	switch (std::rand() % 3)
	{
	case 0:
		return (new A);
		break;
	case 1:
		return (new B);
		break;
	case 2:
		return (new C);
		break;
	}
	return 0; 
}

void identify(Base* p)
{
	try
	{
		A &lol = dynamic_cast< A& > (*p);
		std::cout << "Type : A" << std::endl;
		(void) lol;
	}
	catch(const std::exception& e1)
	{
		(void) e1;
		try
		{
			B &lol = dynamic_cast< B& > (*p);
			std::cout << "Type : B" << std::endl;
			(void) lol;
		}
		catch(const std::exception& e2)
		{
			(void) e2;
			try
			{
				C &lol = dynamic_cast< C& > (*p);
				std::cout << "Type : C" << std::endl;
				(void) lol;
			}
			catch(const std::exception& e3)
			{
				(void) e3;
				std::cout << "I don't know what is this this, but go fuck yourself. I can only reconised A, B and C." << std::endl;
			}
		}
	}
}

void identify(Base& p)
{
	try
	{
		A &lol = dynamic_cast< A& > (p);
		std::cout << "Type : A" << std::endl;
		(void) lol;
	}
	catch(const std::exception& e1)
	{
		(void) e1;
		try
		{
			B &lol = dynamic_cast< B& > (p);
			std::cout << "Type : B" << std::endl;
			(void) lol;
		}
		catch(const std::exception& e2)
		{
			(void) e2;
			try
			{
				C &lol = dynamic_cast< C& > (p);
				std::cout << "Type : C" << std::endl;
				(void) lol;
			}
			catch(const std::exception& e3)
			{
				(void) e3;
				std::cout << "I don't know what is this this, but go fuck yourself. I can only reconised A, B and C." << std::endl;
			}
		}
	}
}

int main()
{
	std::srand((unsigned)time(0));

	Base * xd = new A;
	Base * xd2 = new B;
	Base * xd3 = new C;
	identify(xd);
	identify(xd2);
	identify(xd3);
	identify(*xd);
	identify(*xd2);
	identify(*xd3);

	std::cout << std::endl << std::endl << std::endl;
	Base * test1 = generate();
	identify(test1);
	identify(*test1);
	Base * test2 = generate();
	identify(test2);
	identify(*test2);
	Base * test3 = generate();
	identify(test3);
	identify(*test3);
	return (0);
}