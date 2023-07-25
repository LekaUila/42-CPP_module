/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:56:47 by lflandri          #+#    #+#             */
/*   Updated: 2023/07/25 16:16:12 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class ClapTrap 
{
private:



protected:

	std::string		__Name;
	unsigned int	__Hit_Points;
	int				__Energy_points;
	int				__Attack_Damage;

	ClapTrap(std::string name, int hp, int ep, int atk);

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
	unsigned int get_hp() const;
	int get_ep() const;
	int get_atk() const;
	
};
