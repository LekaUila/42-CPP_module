/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:57:13 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/17 17:33:14 by lflandri         ###   ########.fr       */
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
	friend std::ostream& operator<<(std::ostream &out, const Fixed &obj);
	int operator==(const Fixed &other) const; //comparaison operator
	int operator<=(const Fixed &other) const; 
	int operator>=(const Fixed &other) const;
	int operator!=(const Fixed &other) const;
	int operator>(const Fixed &other) const;
	int operator<(const Fixed &other) const;
	Fixed operator+( const Fixed &snd) const; //aritemetic operator
	Fixed operator-( const Fixed &snd) const;
	Fixed operator*( const Fixed &snd) const;
	Fixed operator/( const Fixed &snd) const;
	Fixed& operator++(); // pré-incrémentation
	Fixed& operator--(); // pré-décrémentation
	Fixed operator++(int); //post-incrémentation
	Fixed operator--(int); //post-décrémentation


	int getRawBits(void) const;
	void setRawBits(int const raw); 
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed& max(const Fixed &first, const Fixed &snd);
	static Fixed& min(const Fixed &first, const Fixed &snd);
	static Fixed& max(Fixed &first, Fixed &snd);
	static Fixed& min(Fixed &first, Fixed &snd);
};
