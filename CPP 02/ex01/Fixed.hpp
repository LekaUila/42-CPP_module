/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:57:13 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/23 11:56:43 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed 
{
private:

	int					nb;
	static const int	virgul_place;

public:

	Fixed();					//constructor
	Fixed(const int number);
	Fixed(const double number);
	~Fixed();							//destructor
	Fixed (const Fixed &obj);				//copie constructor
	Fixed& operator=(const Fixed& x);		//assignation constructor


	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

};
std::ostream& operator<<(std::ostream &out, const Fixed &obj);