/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:28:25 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 15:38:49 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON
#define WEAPON
#include <string>

class Weapon
{
private:
	
	std::string type;

public:
	Weapon(std::string type);
	~Weapon();

	const std::string &gettype(void) const;
	void setType(std::string type);
};
#endif