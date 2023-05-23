/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:18:41 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/09 16:02:21 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::list<int> l1;
	std::vector<int> v1(3);

	l1.push_back(42);
	l1.push_back(9);
	l1.push_back(5);
	l1.push_back(8);
	l1.push_back(6);
	l1.push_back(42);
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;


	std::cout << easyfind(l1, 42) << std::endl;
	std::cout << easyfind(l1, 9) << std::endl;
	std::cout << easyfind(l1, 6) << std::endl << std::endl;

	std::cout << easyfind(v1, 1) << std::endl;
	std::cout << easyfind(v1, 2) << std::endl;
	std::cout << easyfind(v1, 3) << std::endl;
	std::cout << easyfind(v1, 4) << std::endl;

	return (0);
}