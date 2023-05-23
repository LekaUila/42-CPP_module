/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:31:21 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/03 11:51:30 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form::Form("ShrubberyCreationForm", 145, 137), __target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm &obj)
: Form::Form(obj), __target(obj.getTarget())
{
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& x)
{
	this->Form::operator=(x);
	this->__target = x.getTarget();
	return (*this);
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return (this->__target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	
	Form::execute(executor);
	std::string file = this->__target + "_shrubbery";
	std::ofstream file_output(file.c_str(), std::ios::out | std::ios::trunc); 
	if(!file_output.is_open())  
		return ;
	file_output << "                                                         . "<< std::endl << "\
                                              .         ;  "<< std::endl << "\
                 .              .              ;%     ;;   "<< std::endl << "\
                   ,           ,                :;%  %;   "<< std::endl << "\
                    :         ;                   :;%;'     .,   "<< std::endl << "\
           ,.        %;     %;            ;        %;'    ,;"<< std::endl << "\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'"<< std::endl << "\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' "<< std::endl << "\
               ;%;      %;        ;%;        % ;%;  ,%;'"<< std::endl << "\
                `%;.     ;%;     %;'         `;%%;.%;'"<< std::endl << "\
                 `:;%.    ;%%. %@;        %; ;@%;%'"<< std::endl << "\
                    `:%;.  :;bd%;          %;@%;'"<< std::endl << "\
                      `@%:.  :;%.         ;@@%;'   "<< std::endl << "\
                        `@%.  `;@%.      ;@@%;         "<< std::endl << "\
                          `@%%. `@%%    ;@@%;        "<< std::endl << "\
                            ;@%. :@%%  %@@%;       "<< std::endl << "\
                              %@bd%%%bd%%:;     "<< std::endl << "\
                                #@%%%%%:;;"<< std::endl << "\
                                %@@%%%::;"<< std::endl << "\
                                %@@@%(o);  . '         "<< std::endl << "\
                                %@@@o%;:(.,'         "<< std::endl << "\
                            `.. %@@@o%::;         "<< std::endl << "\
                               `)@@@o%::;         "<< std::endl << "\
                                %@@(o)::;        "<< std::endl << "\
                               .%@@@@%::;         "<< std::endl << "\
                               ;%@@@@%::;.          "<< std::endl << "\
                              ;%@@@@%%:;;;. "<< std::endl << "\
                          ...;%@@@@@%%:;;;;,.." << std::endl;
	file_output.close();
}
