/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:06:16 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:32:46 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA
# define AMATERIA
# include <iostream>
# include "ICharacter.hpp"
class AMateria 
{
private:

	/* data */

protected:

	std::string __type;

public:
		
	AMateria(std::string const &type);//constructor
	virtual ~AMateria();							//destructor
	AMateria (const AMateria &obj);				//copie constructor
	AMateria& operator=(const AMateria& x);		//assignation constructor

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);


};
#endif 