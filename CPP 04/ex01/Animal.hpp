/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:31:15 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 16:42:42 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
private:

protected:

	std::string type;

public:

	Animal();					//constructor
	Animal(std::string t);
	virtual ~Animal();							//destructor
	Animal (const Animal &obj);				//copie constructor
	Animal& operator=(const Animal& x);		//assignation constructor

	std::string getType() const;
	virtual void makeSound() const;
};

#endif