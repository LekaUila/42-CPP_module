/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:26:35 by lflandri          #+#    #+#             */
/*   Updated: 2023/07/05 11:26:54 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
	int i = 0;

	while (i != N)
	{
		horde[i].setname(name);
		i++;
	}

	return (horde);
}
