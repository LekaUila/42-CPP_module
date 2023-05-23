/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:01:36 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/01 17:31:25 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM
# include <cstdlib>
# include <ctime> 
# include "Form.hpp"
#include "Bureaucrat.hpp"
class RobotomyRequestForm : public Form
{
private:

	std::string __target;

protected:

	/* data */

public:

	RobotomyRequestForm(std::string target);					//constructor
	~RobotomyRequestForm();							//destructor
	RobotomyRequestForm (const RobotomyRequestForm &obj);				//copie constructor
	RobotomyRequestForm& operator=(const RobotomyRequestForm& x);		//assignation constructor

	const std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
 
};
#endif
