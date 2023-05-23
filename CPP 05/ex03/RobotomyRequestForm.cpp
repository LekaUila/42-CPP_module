/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:45:57 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/01 18:09:15 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form::Form("RobotomyRequestForm", 72, 45), __target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm &obj)
: Form::Form(obj), __target(obj.getTarget())
{
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& x)
{
	this->Form::operator=(x);
	this->__target = x.getTarget();
	return (*this);
}

const std::string RobotomyRequestForm::getTarget() const
{
	return (this->__target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	
	Form::execute(executor);
	std::srand((unsigned)time(0));
	if (std::rand() % 2 == 1)
	{
		std::cout << "\e[0;31m\e[5m\e[4mWARNING WARNING AN ERROR OCCURED\e[25m\e[24m\e[1;37m" << std::endl 
			<< "The robotomy of " << this->__target << " haven't work.\e[0;m" << std::endl;
	}
	else
	{
		std::cout << "\e[0;37mThis is an \e[0;33m\e[5m\e[4mINFORMATIVE MESSAGE\e[25m\e[24m\e[1;37m." << std::endl 
			<< "The robotomy of " << this->__target << " is done correctly.\e[0;m" << std::endl;	
	}
}
