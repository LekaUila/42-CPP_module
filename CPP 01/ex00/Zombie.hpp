/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:08:53 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/07 11:50:44 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie
{
private:
	
std::string name;

public:
	Zombie(std::string name);
	~Zombie();

	void announce( void );
};


Zombie* newZombie( std::string name );
void randomChump( std::string name );


