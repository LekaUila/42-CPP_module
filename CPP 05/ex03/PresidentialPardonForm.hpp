/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:01:43 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/01 16:01:44 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM
# define PRESIDENTIALPARDONFORM
# include "Form.hpp"
#include "Bureaucrat.hpp"
class PresidentialPardonForm : public Form
{
private:

	std::string __target;

protected:

	/* data */

public:

	PresidentialPardonForm(std::string target);					//constructor
	~PresidentialPardonForm();							//destructor
	PresidentialPardonForm (const PresidentialPardonForm &obj);				//copie constructor
	PresidentialPardonForm& operator=(const PresidentialPardonForm& x);		//assignation constructor

	const std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
 
};
#endif
