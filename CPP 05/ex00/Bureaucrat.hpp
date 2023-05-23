/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:52:37 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/02 17:17:57 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT
# define BUREAUCRAT
#include <iostream>
class Bureaucrat 
{
private:

	const std::string	name;
	int					grade;
	class GradeTooHighException : public std::logic_error
	{
	
	public:
		GradeTooHighException()
		: std::logic_error::logic_error("Grade Too High : Must be 0 < Grade < 151")
		{}
	};
	class GradeTooLowException : public std::logic_error
	{
	
	public:
		GradeTooLowException()
		: std::logic_error::logic_error("Grade Too Low : Must be 0 < Grade < 151")
		{}
	};

protected:

	/*data*/

public:

	Bureaucrat(std::string n, int g);					//constructor
	~Bureaucrat();							//destructor
	Bureaucrat (const Bureaucrat &obj);				//copie constructor
	Bureaucrat& operator=(const Bureaucrat& x);		//assignation constructor

	const std::string getName() const;
	int getGrade() const;
	void upGrade(int i);
	void downGrade(int i);
	

 
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);
#endif
