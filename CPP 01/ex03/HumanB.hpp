/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:32:32 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 15:34:38 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
private:
	
	Weapon 		*weapon;
	std::string name;


public:
	HumanB(std::string name);
	~HumanB();
	
	void attack();
	void setWeapon(Weapon &weapon);
};