/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:52:39 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/02 17:31:38 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
# include "Form.hpp"

Bureaucrat::Bureaucrat(std::string n, int g)
: name(n), grade(g)
{
	if (g > 150)
		throw Bureaucrat::GradeTooLowException();
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat (const Bureaucrat &obj)
: name(obj.getName()), grade(obj.getGrade())
{
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& x)
{
	this->grade = x.getGrade();
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}
int Bureaucrat::getGrade() const
{
	return (this->grade);
}
void Bureaucrat::upGrade(int i)
{
	if (this->grade - i > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->grade - i < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= i;
}
void Bureaucrat::downGrade(int i)
{
	if (this->grade + i > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->grade + i < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade += i;
}

void Bureaucrat::signForm(Form &obj) const
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->name << " signed " << obj.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn't sign " << obj.getName() << " because " << e.what() << "." << std::endl;
	}
	
}

void Bureaucrat::executeForm(Form const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn't execute " << form.getName() << " because " << e.what() << "." << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << "\e[0;36m" << obj.getName() << "\e[0;m, bureaucrat grade \e[1;33m" << obj.getGrade() << "\e[0;m";
	return (out);
}
