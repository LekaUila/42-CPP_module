/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:37 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/23 11:33:38 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP 
# include "main_header.hpp"



class Dog : public Animal {
private:

	/* data */

public:

	Dog(/* args */);					//constructor
	~Dog();							//destructor
	Dog (const Dog &obj);				//copie constructor
	Dog& operator=(const Dog& x);		//assignation constructor
	void makeSound() const;
};
#endif