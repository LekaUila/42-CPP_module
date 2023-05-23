/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:33:44 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/01 18:41:09 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN
# define INTERN
# include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Intern 
{
private:

	/* data */

protected:

	/* data */

public:

	Intern(/* args */);					//constructor
	~Intern();							//destructor
	Intern (const Intern &obj);				//copie constructor
	Intern& operator=(const Intern& x);		//assignation constructor

	Form *makeForm(std::string form, std::string target) const;
 
};
#endif
