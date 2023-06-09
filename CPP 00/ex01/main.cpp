/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:58:15 by lflandri          #+#    #+#             */
/*   Updated: 2023/06/22 13:12:57 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook_Class.hpp"

int main(void)
{
	PhoneBook			pbook;
	std::string			command = "NOTEXIT";

	while (command != "EXIT")
	{
		std::cout << "\e[0;36mEnter your order : \e[0;m" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command == "ADD")
			pbook.ADD();
		else if (command == "SEARCH")
			pbook.SEARCH();
		else if (command == "EXIT")
			break;
		else
			std::cout << "\e[0;31mSorry, I can't understand your order. I know it's hard to tap on your keyboard, but please, make an effort.\e[0;m" << std::endl;
	}

	return (0);
}