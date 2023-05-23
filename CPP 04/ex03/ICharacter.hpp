/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:31:55 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:35:50 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER
# define ICHARACTER
# include <iostream>
//# include "AMateria.hpp"
class AMateria ;
class ICharacter 
{
private:

	/* data */

protected:

	/* data */

public:

	ICharacter(/* args */);					//constructor
	virtual ~ICharacter() ;							//destructor
	ICharacter (const ICharacter &obj);				//copie constructor
	ICharacter& operator=(const ICharacter& x);		//assignation constructor
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;


};
#endif 