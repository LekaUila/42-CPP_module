/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:31:15 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/23 11:39:03 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
private:

protected:

	std::string type;

public:

	WrongAnimal();					//constructor
	WrongAnimal(std::string t);
	~WrongAnimal();							//destructor
	WrongAnimal (const WrongAnimal &obj);				//copie constructor
	WrongAnimal& operator=(const WrongAnimal& x);		//assignation constructor

	std::string getType() const;
	void makeSound() const;
};

#endif