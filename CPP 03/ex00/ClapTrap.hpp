/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:56:47 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/19 11:33:03 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class ClapTrap 
{
private:

	std::string	__Name;
	int			__Hit_Points;
	int			__Energy_points;
	int			__Attack_Damage;

public:

	ClapTrap(void);					//constructor
	ClapTrap(std::string name);
	~ClapTrap();							//destructor
	ClapTrap (const ClapTrap &obj);				//copie constructor
	ClapTrap& operator=(const ClapTrap& x);		//assignation constructor


	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string get_name() const;
	int get_hp() const;
	int get_ep() const;
	int get_atk() const;
	
};
