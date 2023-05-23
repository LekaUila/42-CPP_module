/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:35 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/23 11:33:35 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "main_header.hpp"



class Cat : public Animal
{
private:

	/* data */

public:

	Cat(/* args */);					//constructor
	~Cat();							//destructor
	Cat (const Cat &obj);				//copie constructor
	Cat& operator=(const Cat& x);		//assignation constructor
	void makeSound() const;
};

#endif
