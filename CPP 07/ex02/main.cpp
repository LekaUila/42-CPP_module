/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:24:13 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/08 15:37:01 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

int main(void)
{
	Array< int > tab1(10);
	std::cout << tab1 << std::endl;
	for (unsigned int i = 0; i < 10; i++)
	{
		tab1[i] = i;
	}
	std::cout << tab1 << std::endl;

	Array< int > tab2(tab1);
	std::cout << tab2 << std::endl;
	for (unsigned int i = 0; i < 10; i++)
	{
		tab2[i]++;
	}
	std::cout << tab1 << std::endl;
	std::cout << tab2 << std::endl;

	Array< std::string > tab45(3);
	Array< std::string > tab46(4);
	std::cout << tab45 << std::endl;
	std::cout << tab46 << std::endl;
	for (unsigned int i = 0; i < 3; i++)
	{
		tab45[i] = "chausette";
		tab46[i] = "chaussure";
	}
	tab46[3] = "chaussure";
	std::cout << tab45 << std::endl;
	std::cout << tab46 << std::endl;
	tab46 = tab45;
	std::cout << tab45 << std::endl;
	std::cout << tab46 << std::endl;
	tab45[1] = "chausette rose";
	std::cout << tab45 << std::endl;
	std::cout << tab46 << std::endl;
	return (0);
}