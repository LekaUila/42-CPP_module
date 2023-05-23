/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:28:09 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/26 15:38:40 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain( std::string level )
{
	void		(Harl::*tab_f[4])(void);
	std::string tab_s[4];
	int			i;

	tab_f[0] = &Harl::debug;
	tab_f[1] = &Harl::info;
	tab_f[2] = &Harl::warning;
	tab_f[3] = &Harl::error;
	tab_s[0] = "DEBUG";
	tab_s[1] = "INFO";
	tab_s[2] = "WARNING";
	tab_s[3] = "ERROR";

	i = 0;
	while (i != 4)
	{
		if (tab_s[i] == level)
		{
			((*this).*tab_f[i])();
			break;
		}
		i++;
	}
	if (i == 4)
	{
			std::cout << "Input Error" << std::endl;
	}
}

void Harl::complain_filter( std::string level )
{
	std::string tab_s[4];
	int			i;

	tab_s[0] = "DEBUG";
	tab_s[1] = "INFO";
	tab_s[2] = "WARNING";
	tab_s[3] = "ERROR";

	i = 0;
	while (i != 4)
	{
		if (tab_s[i] == level)
		{
			switch (i)
			{
			case 0: 
				this->debug();
				 //FALLTHRU
			case 1:
				this->info();
				/* FALLTHRU                                */
			case 2:
				this->warning();
				/*FALLTHRU*/
			case 3:
				this->error();
				break;
			}
			break;
		}
		i++;
	}
	if (i == 4)
	{
			std::cout << "Input Error" << std::endl;
	}
}

void Harl::debug(void)
{
	std::cout << "\e[1;37mYou have succesfuly create a programme \e[0;35mwithout bug \e[1;37m!" << std::endl << "\e[1;32m\e[5m!!! CONGRATULATIONS DUMB FACE !!!\e[25m\e[0;m" << std::endl;
}
void Harl::info(void)
{
	std::cout << "\e[1;37mYou have an \e[1;36mINFO ALERTE\e[1;37m, you can't visibly read a documentation." << std::endl << "\e[1;32m\e[5m!!! CONGRATUATION, YOU'RE ILLITERATE !!!\e[25m\e[0;m" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "\e[1;37mYou have a \e[0;33mWARNING ALERTE\e[1;37m, you are visibly as stupid as a \e[1;35mHONKAI\e[1;37m player." << std::endl << "\e[1;32m\e[5m!!! CONGRATUATION, YOU'RE VERY STUPID !!!\e[25m\e[0;m" << std::endl;
}
void Harl::error(void)
{
	std::cout << "\e[1;37mYou have an \e[0;31mERROR ALERTE\e[1;37m, even my ass is smarter than you." << std::endl << "\e[1;32m\e[5m!!! CONGRATUATION, YOU'RE ADOPTED !!!\e[25m\e[0;m" << std::endl;
}