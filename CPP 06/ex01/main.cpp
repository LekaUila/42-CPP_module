/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:47:48 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/15 11:02:19 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data d;
	Data *pd = &d;

	d.i = 42;
	d.c = 'Z';
	std::cout << "Data :" << std::endl << pd << std::endl << pd->i << std::endl << pd->c << std::endl;

	uintptr_t raw = Serializer::serialize(pd);
	std::cout << raw << std::endl;

	Data *nd = Serializer::deserialize(raw);

	std::cout << "Data :" << std::endl << nd << std::endl << nd->i << std::endl << nd->c << std::endl;

	return (0);
}