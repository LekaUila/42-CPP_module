/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:57:15 by lflandri          #+#    #+#             */
/*   Updated: 2023/07/25 16:14:51 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap claptrap;
	ClapTrap lol("lol");
	ClapTrap leka("Leka");
	ClapTrap pouet("pouet");
	ClapTrap pouet2(pouet);

	claptrap.attack("lol");
	claptrap.attack("lol");
	claptrap.attack("lol");
	claptrap.attack("lol");
	claptrap.attack("lol");
	claptrap.attack("lol");
	claptrap.attack("lol");
	claptrap.attack("lol");
	claptrap.attack("lol");
	claptrap.attack("lol");
	claptrap.attack("lol");
	pouet.takeDamage(11);
	pouet.takeDamage(165165);
	lol.takeDamage(5);
	lol.beRepaired(3);

	claptrap = lol;
	lol.takeDamage(8);
}