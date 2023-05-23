/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:58:12 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/08 16:59:07 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook_Class.hpp"

PhoneBook::PhoneBook()
{
	this->__old = 0;
	this->__nb_contact = 0;
}

PhoneBook::~PhoneBook()
{
}

std::string	get_enter()
{
	char	str[9999];
	std::string	strr;
	std::cin.getline(str, 9999);
	strr = str;
	return strr;
}

void PhoneBook::ADD()
{
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phone_number = "";
	std::string darkest_secret = "";
	std::string tempo = "";
	size_t i;


	while (first_name.empty())
	{
		std::cout << "\e[0;36mEnter the first name : \e[0;m" << std::endl;
		first_name = get_enter();
	}
	while (last_name.empty())
	{
		std::cout << "\e[0;36mEnter the last name : \e[0;m" << std::endl;
		last_name = get_enter();
	}
	while (nickname.empty())
	{
		std::cout << "\e[0;36mEnter the nickname : \e[0;m" << std::endl;
		nickname = get_enter();
	}
	while (phone_number.empty())
	{
		std::cout << "\e[0;36mEnter the phone number : \e[0;m" << std::endl;
		tempo = "";
		tempo = get_enter();
		i = 0;
		while (i != tempo.size())
		{
			if (tempo[i] < '0' || tempo[i] > '9')
			{
				break;
			}
			i++;
		}
		if (i == tempo.size())
			phone_number = tempo;
		else
			std::cout << "\e[0;31mI need a number. I know your IQ is limited. But I am sure, if you try with all your brain, you can tap the phone number correctly.\e[0;m" << std::endl;
	}
	while (darkest_secret.empty())
	{
		std::cout << "\e[0;36mEnter the darkest secret : \e[0;m" << std::endl;
		darkest_secret = get_enter();
	}
	if (this->__nb_contact == 8)
	{
		this->__tab[this->__old].set_first_name(first_name);
		this->__tab[this->__old].set_last_name(last_name);
		this->__tab[this->__old].set_nickname(nickname);
		this->__tab[this->__old].set_phone_number(phone_number);
		this->__tab[this->__old].set_darkest_secret(darkest_secret);
		this->__old++;
		if (this->__old == 8)
			this->__old = 0;
	}
	else
	{
		this->__tab[this->__nb_contact].set_first_name(first_name);
		this->__tab[this->__nb_contact].set_last_name(last_name);
		this->__tab[this->__nb_contact].set_nickname(nickname);
		this->__tab[this->__nb_contact].set_phone_number(phone_number);
		this->__tab[this->__nb_contact].set_darkest_secret(darkest_secret);
		this->__nb_contact++;
	}
}

static std::string ft_format(std::string str)
{
	std::string str_new = str;
	
	while (str_new.size() < 10)
		str_new.insert(0, " ");
	if (str_new.size() > 10)
		str_new.replace(9, str_new.size() - 9, ".");
	return 	str_new;
}

static void ft_format_and_print(Contact cont)
{
	std::cout << ft_format(cont.get_first_name()) << "\e[0;35m|\e[0;36m" <<
		ft_format(cont.get_last_name()) << "\e[0;35m|\e[0;36m" <<
		ft_format(cont.get_nickname()) << "\e[0;35m|\e[0;m" <<
		std::endl;
}

void PhoneBook::SEARCH()
{
	int	i = 0;
	std::string	index;

	if (this->__nb_contact == 0)
	{
		std::cout << "\e[0;31mYou are a virgin and single geek, do you really think you have enough friends to have just only one contacts?\e[0;m" << std::endl;
		return ;
	}
	std::cout << "\e[0;35m_____________________________________________\e[0;m" << std::endl;
	while (i != this->__nb_contact)
	{
		std::cout << "\e[0;35m|\e[0;36m         " << i << "\e[0;35m|\e[0;36m";
		ft_format_and_print(this->__tab[i]);
		std::cout << "\e[0;35m|__________|__________|__________|__________|\e[0;m" << std::endl;
		i++;
	}
	while (1)
	{
		std::cout << "Enter the index of the contact : " << std::endl;
		index = get_enter();
		if (index.empty())
			std::cout << "\e[0;31mI need an index. I know you are a lazy, but you juste need to tap on a number.\e[0;m" << std::endl;
		else if (index.size() != 1)
			std::cout << "\e[0;31mI need a correct index. I know you are a stupid, but you juste need to tap on a number, not two or more.\e[0;m" << std::endl;
		else if (index[0] > '9' || index[0] < '0')
			std::cout << "\e[0;31mThis is not a number. I need a number. Did you already go to school? I'm starting to doubt it.\e[0;m" << std::endl;
		else if (index[0] >= this->__nb_contact + '0')
			std::cout << "\e[0;31mI need a correct index. you are a virgin and single geek, do you really think you have enough friends to have more than " << this->__nb_contact << " contacts?\e[0;m" << std::endl;
		else if (index[0] >= '0' && index[0] < this->__nb_contact + '0')
			break;
	}
	i = index[0] - '0';
std::cout << "\e[0;35mFirst Name : \e[0;36m" << this->__tab[i].get_first_name() << "\e[0;m" << std::endl;
std::cout << "\e[0;35mLast Name : \e[0;36m" << this->__tab[i].get_last_name() << "\e[0;m" << std::endl;
std::cout << "\e[0;35mNickname : \e[0;36m" << this->__tab[i].get_nickname() << "\e[0;m" << std::endl;
std::cout << "\e[0;35mPhone Number : \e[0;36m" << this->__tab[i].get_phone_number() << "\e[0;m" << std::endl;
std::cout << "\e[0;35mDarkest secret : \e[0;36m" << this->__tab[i].get_darkest_secret() << "\e[0;m" << std::endl;
}

