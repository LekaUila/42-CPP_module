/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:08:22 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 12:52:30 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *uzhez = newZombie("Uzhez");
	Zombie *tzom = newZombie("Tzom'zooreg");
	Zombie *areagriz = newZombie("Areagrizz");
	Zombie *sqir = newZombie("Sqir'qas");
	Zombie *vhesgooquk = newZombie("vhesgooquk");
	
	randomChump("Brok'zix");
	uzhez->announce();
	sqir->announce();
	randomChump("Srun'qulug");
	areagriz->announce();
	tzom->announce();
	delete uzhez;
	delete sqir;
	vhesgooquk->announce();
	delete areagriz;
	delete tzom;
	delete vhesgooquk;

	int i = 0;
	Zombie	*horde = zombieHorde(42, "Oczag");
	while (i != 42)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	
	return (0);
}