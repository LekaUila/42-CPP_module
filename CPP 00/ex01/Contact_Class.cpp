/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:58:18 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/06 14:14:29 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact_Class.hpp"

Contact::Contact()
:	__first_name(""),
	__last_name(""),
	__nickname(""),
	__phone_number(""),
	__darkest_secret("")
{
}

Contact::~Contact()
{
}

//GET
std::string Contact::get_first_name(void)
{
	return this->__first_name;
}
std::string Contact::get_last_name(void)
{
	return this->__last_name;
}
std::string Contact::get_nickname(void)
{
	return this->__nickname;
}
std::string Contact::get_phone_number(void)
{
	return this->__phone_number;
}
std::string Contact::get_darkest_secret(void)
{
	return this->__darkest_secret;
}


//SET
void Contact::set_first_name(std::string first_name)
{
	this->__first_name = first_name;
}
void Contact::set_last_name(std::string last_name)
{
	this->__last_name = last_name;
}
void Contact::set_nickname(std::string nickname)
{
	this->__nickname = nickname;
}
void Contact::set_phone_number(std::string phone_number)
{
	this->__phone_number = phone_number;
}
void Contact::set_darkest_secret(std::string darkest_secret)
{
	this->__darkest_secret = darkest_secret;
}