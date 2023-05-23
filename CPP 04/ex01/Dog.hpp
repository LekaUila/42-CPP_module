/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:37 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 12:54:33 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP 
# include "main_header.hpp"



class Dog : public Animal {
private:

	Brain *brain; 

public:

	Dog(/* args */);					//constructor
	~Dog();							//destructor
	Dog (const Dog &obj);				//copie constructor
	Dog& operator=(const Dog& x);		//assignation constructor
	void makeSound() const;
	void PrintIdeas() const;
	void SetIdeas(unsigned int ind, std::string ideas);
};
#endif