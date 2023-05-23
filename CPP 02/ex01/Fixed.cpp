/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:57:10 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/23 11:57:25 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::virgul_place = 8;

static int	ft_puissance(int nb, int p)
{
	if (p == 0)
		return (1);
	if (p == 1)
		return (nb);
	return (nb * ft_puissance(nb, p - 1));
}

Fixed::Fixed()
:nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	int	i;

std::cout << "Int constructor called" << std::endl;
	this->nb = number;
	i = 0;
	while (i != Fixed::virgul_place)
	{
		this->nb*=2;
		i++;
	}
}

Fixed::Fixed(const double number)
{
	std::cout << "Float constructor called" << std::endl;

	float number_bis = number * ft_puissance(2, Fixed::virgul_place);
	float check = ( number_bis - int(number_bis)) * 10;
	this->nb = number_bis;
	if (check >= 5)
		this->nb++;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->nb = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->nb = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->nb);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->nb = raw;
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}

float Fixed::toFloat(void) const
{
	double number = this->nb;

	return number / ft_puissance(2, Fixed::virgul_place);
}

int Fixed::toInt(void) const
{
	int	i;
	int number;

	number = this->nb;
	i = 0;
	while (i != Fixed::virgul_place)
	{
		number = number / 2;
		i++;
	}
	return number;
}