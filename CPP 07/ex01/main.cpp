/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:17:33 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/22 12:16:53 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"




void add_stroumph(std::string & elt)
{
	elt+= "stroumf";
}

void save_first_char(std::string & elt)
{
	elt= elt.at(0);
}

template< typename T >
void printelt(T  & elt)
{
	std::cout << elt << std::endl;
}

void add_one(int  & elt)
{
	elt++;
}

int main(void)
{
	std::string tab[5] = {"Coucou", "tu", "vas", "bien", "?"};
	iter(tab, 5, printelt);
	std::cout << std::endl;
	iter(tab, 5, add_stroumph);
	std::cout << std::endl;
	iter(tab, 5, printelt);
	std::cout << std::endl;
	iter(tab, 5, save_first_char);
	std::cout << std::endl;
	iter(tab, 5, printelt);
	std::cout << std::endl;

	int tab_int[10] = {1, 654, 65841, 65814, 321, 684, 3, 5, 6, 98};
	iter(tab_int, 10, printelt);
	std::cout << std::endl;
	iter(tab_int, 10, add_one);
	std::cout << std::endl;
	iter(tab_int, 10, printelt);



	return (0);
}