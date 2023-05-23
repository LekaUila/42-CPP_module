/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:03:53 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 14:17:25 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "L'adresse de la string en mémoire : " << &str << std::endl;
	std::cout << "L'adresse stockée dans stringPTR : " << stringPTR << std::endl;
	std::cout << "L'adresse stockée dans stringREF : " << &stringREF << std::endl;


	std::cout << "La valeur de la string : " << str << std::endl;
	std::cout << "La valeur pointée par stringPTR : " << *stringPTR << std::endl;
	std::cout << "La valeur pointée par stringREF : " << stringREF << std::endl;
	return (0);
}