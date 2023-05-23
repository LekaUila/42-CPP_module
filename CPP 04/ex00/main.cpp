/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:57:15 by lflandri          #+#    #+#             */
/*   Updated: 2023/03/22 11:28:37 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.hpp"

int main( void )
{

const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << meta->getType() << " " << std::endl;

i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;

std::cout << std::endl << std::endl << std::endl;
Animal lol =  Dog();
std::cout << lol.getType() << " " << std::endl;
lol.makeSound();
lol =  Cat();
std::cout << lol.getType() << " " << std::endl;
lol.makeSound();
lol =  Dog();
std::cout << lol.getType() << " " << std::endl;
lol.makeSound();


std::cout << std::endl << std::endl << std::endl;
Dog dd = Dog();
Cat cc = Cat();

Animal *lol2 =  &dd;
std::cout << lol2->getType() << " " << std::endl;
lol2->makeSound();
lol2 =  &cc;
std::cout << lol2->getType() << " " << std::endl;
lol2->makeSound();
lol2 =  &dd;
std::cout << lol2->getType() << " " << std::endl;
lol2->makeSound();
std::cout << std::endl << std::endl << std::endl;

const WrongAnimal* meta2 = new WrongAnimal();
const WrongAnimal* i2 = new WrongCat();

std::cout << i2->getType() << " " << std::endl;
std::cout << meta2->getType() << " " << std::endl;

i2->makeSound(); //will output the cat sound!
meta2->makeSound();
delete meta2;
delete i2;

std::cout << std::endl << std::endl << std::endl;
return 0;
}