/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:02:10 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/08 16:57:41 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS
#define PHONEBOOK_CLASS

#include "Contact_Class.hpp"
#include <iostream>

class PhoneBook
{
private:

	int		__old;
	int		__nb_contact;
	Contact __tab[8];
	

public:

	PhoneBook();
	~PhoneBook();

	// GET
	void ADD();
	void SEARCH();
	//SET

};

std::string get_enter(void);

#endif