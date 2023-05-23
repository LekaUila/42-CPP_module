/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:00:51 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 15:31:50 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
private:
	
	Weapon 		*weapon;
	std::string name;


public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	
	void attack();
};


