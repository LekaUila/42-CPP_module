/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:19:11 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/15 11:53:00 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		ScalarConverter::convert(av[i]);
		if (i != ac -1)
			std::cout << std::endl;
	}
	return (0);
}