/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:30:15 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:23:53 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE
# define CURE
# include "AMateria.hpp"
# include "ICharacter.hpp"
class Cure : public AMateria
{
private:

	/* data */

protected:

	/* data */

public:

	Cure(/* args */);					//constructor
	~Cure();							//destructor
	Cure (const Cure &obj);				//copie constructor
	Cure& operator=(const Cure& x);		//assignation constructor
	
	void use(ICharacter& target);
	AMateria* clone() const;


};
#endif 