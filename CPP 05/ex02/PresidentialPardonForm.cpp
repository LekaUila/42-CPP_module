/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:45:57 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/01 16:14:36 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form::Form("PresidentialPardonForm", 25, 5), __target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm &obj)
: Form::Form(obj), __target(obj.getTarget())
{
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& x)
{
	this->Form::operator=(x);
	this->__target = x.getTarget();
	return (*this);
}

const std::string PresidentialPardonForm::getTarget() const
{
	return (this->__target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << "\e[0;37mThis is an \e[0;33m\e[5m\e[4mINFORMATIVE MESSAGE\e[25m\e[24m\e[1;37m." << std::endl
		<< "\e[0;36m" << this->__target << "\e[1;37m have been forgiven by \e[7m\e[1;35mZaphod Beeblebrox\e[7m\e[0;m" << std::endl;
}
