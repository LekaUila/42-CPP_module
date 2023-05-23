/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:34:37 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:24:27 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIASOURCE
# define MATERIASOURCE
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
class MateriaSource : public IMateriaSource
{
private:

	/* data */

protected:

	AMateria *__inventory[4];

public:

	MateriaSource(/* args */);					//constructor
	~MateriaSource();							//destructor
	MateriaSource (const MateriaSource &obj);				//copie constructor
	MateriaSource& operator=(const MateriaSource& x);		//assignation constructor
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
	const AMateria * getinventorytoind(int ind) const;


};
#endif 