/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:26:57 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/02 17:34:25 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(std::string n, int gs, int ge)
:__name(n), __grade_need_to_sign(gs), __grade_need_to_exe(ge), __is_signed(false)
{
	if (ge > 150)
		throw Form::GradeTooLowException();
	if (ge < 1)
		throw Form::GradeTooHighException();
	if (gs > 150)
		throw Form::GradeTooLowException();
	if (gs < 1)
		throw Form::GradeTooHighException();
}

Form::~Form()
{
}

Form::Form (const Form &obj)
:__name(obj.getName()), __grade_need_to_sign(obj.getGradeToSign()), __grade_need_to_exe(obj.getGradeToExe()),  __is_signed(obj.isSigned())
{
}
Form& Form::operator=(const Form& x)
{
	this->__is_signed = x.isSigned();
	return (*this);
}

const std::string Form::getName() const
{
	return (this->__name);
}
bool Form::isSigned() const
{
	return (this->__is_signed);
}
int	Form::getGradeToSign() const
{
	return (this->__grade_need_to_sign);
}
int	Form::getGradeToExe() const
{
	return (this->__grade_need_to_exe);
}

void Form::beSigned(Bureaucrat obj)
{
	if (obj.getGrade() > this->__grade_need_to_sign)
		throw Form::GradeTooLowException();
	this->__is_signed = true;
}

void Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->__grade_need_to_exe)
		throw Form::GradeTooLowException();
	if (!this->__is_signed)
		throw Form::FormNotSigned();
}

std::ostream& operator<<(std::ostream &out, const Form &obj)
{
	if (obj.isSigned())
	{
		out << "Form \"\e[1;36m" << obj.getName() << "\e[0;m\" | grade needed [ execute : \e[1;33m" << obj.getGradeToExe() << "\e[0;m ; sign : \e[1;33m" 
			<< obj.getGradeToSign() << "\e[0;m ] This Form is signed.";
	}
	else
	{
		out << "Form \"\e[1;36m" << obj.getName() << "\e[0;m\" | grade needed [ execute : \e[1;33m" << obj.getGradeToExe() << "\e[0;m ; sign : \e[1;33m" 
			<< obj.getGradeToSign() << "\e[0;m ] This Form is not signed.";
	}
	return (out);
}