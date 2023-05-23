/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:35 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 13:02:43 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "main_header.hpp"



class Cat : public Animal
{
private:

	Brain *brain; 

public:

	Cat(/* args */);					//constructor
	~Cat();							//destructor
	Cat (const Cat &obj);				//copie constructor
	Cat& operator=(const Cat& x);		//assignation constructor
	void makeSound() const;
	void PrintIdeas() const;
	void SetIdeas(unsigned int ind, std::string ideas);
};
#endif
