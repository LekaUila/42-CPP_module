/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:53 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/05 18:36:50 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	std::string	toprint;
	int			i;
	size_t		ind;

	i = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	while (ac != i)
	{
		toprint = av[i];
		ind = 0;
		while (ind != toprint.size())
		{
			toprint[ind] = toupper(toprint.at(ind));
			ind++;
		}
		std::cout << toprint;
		i++;
	}
	std::cout << std::endl;
	return (0);
}