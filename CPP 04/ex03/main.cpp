/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:29:40 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 15:28:20 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

int main()
{

	/*Original */
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	

	/*Perso */
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;

	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Cure());
	ICharacter* me2 = new Character("me");
	AMateria* tmp2;
	tmp2 = src2->createMateria("ice");
	me2->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	me2->equip(tmp2);
	ICharacter* bob2 = new Character("bob");
	me2->use(0, *bob2);
	me2->use(1, *bob2);
	delete bob2;
	delete me2;
	delete src2;

	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;


	IMateriaSource* src3 = new MateriaSource();
	src3->learnMateria(new Cure());
	src3->learnMateria(new Ice());
	ICharacter* me3 = new Character("me");
	AMateria* tmp3;
	tmp3 = src3->createMateria("cure");
	me3->equip(tmp3);
	tmp3 = src3->createMateria("cure");
	me3->equip(tmp3);
	AMateria* tempo;
	tempo = src3->createMateria("cure");
	me3->equip(tempo);
	tmp3 = src3->createMateria("cure");
	me3->equip(tmp3);
	ICharacter* bob3 = new Character("bob");
	for (size_t i = 0; i < 4; i++)
	{
		me3->use(i, *bob3);
	}
	std::cout << std::endl;
	me3->unequip(2);
	delete tempo;
	tmp3 = src3->createMateria("ice");
	me3->equip(tmp3);
	for (size_t i = 0; i < 4; i++)
	{
		me3->use(i, *bob3);
	}
	delete bob3;
	delete me3;
	delete src3;

	return 0;
}

