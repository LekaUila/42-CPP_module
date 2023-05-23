/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:41:35 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/26 15:09:01 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongCAT_HPP
# define WRONGWrongCAT_HPP
# include "main_header.hpp"



class WrongCat : public WrongAnimal
{
private:

	/* data */

public:

	WrongCat(/* args */);					//constructor
	~WrongCat();							//destructor
	WrongCat (const WrongCat &obj);				//copie constructor
	WrongCat& operator=(const WrongCat& x);		//assignation constructor
	void makeSound() const;
};

#endif
