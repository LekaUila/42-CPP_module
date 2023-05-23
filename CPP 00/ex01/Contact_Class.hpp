/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:02:20 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/06 14:09:46 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS
#define COMTACT_CLASS

#include <string>

class Contact
{
private:

	std::string __first_name;
	std::string __last_name;
	std::string __nickname;
	std::string __phone_number;
	std::string __darkest_secret;

public:

	Contact();
	~Contact();

	// GET
	std::string get_first_name(void);
	std::string get_last_name(void);
	std::string get_nickname(void);
	std::string get_phone_number(void);
	std::string get_darkest_secret(void);

	//SET
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_nickname(std::string nickname);
	void set_phone_number(std::string phone_number);
	void set_darkest_secret(std::string darkest_secret);
};

#endif