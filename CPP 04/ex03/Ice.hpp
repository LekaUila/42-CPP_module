/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:30:32 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:23:50 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE
# define ICE
# include "AMateria.hpp"
# include "ICharacter.hpp"
class Ice : public AMateria
{
private:

	/* data */

protected:

	/* data */

public:

	Ice(/* args */);					//constructor
	~Ice();							//destructor
	Ice (const Ice &obj);				//copie constructor
	Ice& operator=(const Ice& x);		//assignation constructor

	void use(ICharacter& target);
	AMateria* clone() const;

};

#endif 