/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:30:03 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:31:55 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER
# define CHARACTER
#include "ICharacter.hpp"
#include "AMateria.hpp"
class Character : public ICharacter
{
private:

	/* data */

protected:

	std::string __name;
	AMateria *__inventory[4];

public:

	Character(std::string const name);					//constructor
	~Character();							//destructor
	Character (const Character &obj);				//copie constructor
	Character& operator=(const Character& x);		//assignation constructor
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	const AMateria * getinventorytoind(int ind) const;


};
#endif 