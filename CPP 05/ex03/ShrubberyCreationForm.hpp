/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:01:36 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/01 17:33:36 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM
# include <fstream>
# include "Form.hpp"
# include "Bureaucrat.hpp"
class ShrubberyCreationForm : public Form
{
private:

	std::string __target;

protected:

	/* data */

public:

	ShrubberyCreationForm(std::string target);					//constructor
	~ShrubberyCreationForm();							//destructor
	ShrubberyCreationForm (const ShrubberyCreationForm &obj);				//copie constructor
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& x);		//assignation constructor

	const std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
 
};
#endif
