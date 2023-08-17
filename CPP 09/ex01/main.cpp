/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:09:08 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/17 12:00:57 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac < 2 or av[1][0] == 0)
	{
		std::cout << "Error : No Calculation to do : " << std::endl 
			<< "here is a reminder of use : ./RPN \"\e[1;34myour_calculation\e[0;m\" \"\e[1;34mshow_calculation : \e[0;32myes\e[1;34m or \e[0;31mno\e[1;34m (default : \e[0;31mno\e[1;34m)\e[0;m\"" << std::endl
			<< "\e[0;33m\e[1mStoping execution\e[25m\e[0;m" << std::endl; 
		return (1);
	}
	else if (ac > 3)
	{
		std::cout << "Error : Invalid number of parameter :" << std::endl 
			<< "here is a reminder of use : ./RPN \"\e[1;34myour_calculation\e[0;m\" \"\e[1;34mshow_calculation : \e[0;32myes\e[1;34m or \e[0;31mno\e[1;34m (default : \e[0;31mno\e[1;34m)\e[0;m\"" << std::endl
			<< "\e[0;33m\e[1mStoping execution\e[25m\e[0;m" << std::endl; 
		return (1);
	}
	else
	{
		try
		{
			bool show_detail = false;
			if (ac == 3)
			{
				if ("yes" == (std::string) av[2])
					show_detail = true;
				std::cout << "show calculation : " << (show_detail ? "\e[0;32myes\e[0;m" : "\e[0;31mno\e[0;m") << std::endl;
			}
			RPN::rpnSystem(av[1], show_detail);
				
		}
		catch(const std::exception& e)
		{
			std::cerr << "\e[0;31m\e[5m"  << e.what() << "\e[25m\e[0;m" << '\n';
		}
		
	}
	std::cout << "\e[0;33m\e[1mStoping execution\e[25m\e[0;m" << std::endl; 
	return (0);  
}