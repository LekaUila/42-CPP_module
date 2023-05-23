/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:34:45 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:39:19 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMATERIASOURCE
# define IMATERIASOURCE
# include <iostream>
# include "AMateria.hpp"
class IMateriaSource 
{
private:

	/* data */

protected:

	std::string __type;

public:

	IMateriaSource(/* args */);					//constructor
	virtual ~IMateriaSource() ;							//destructor
	IMateriaSource (const IMateriaSource &obj);				//copie constructor
	IMateriaSource& operator=(const IMateriaSource& x);		//assignation constructor
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;


};
#endif 