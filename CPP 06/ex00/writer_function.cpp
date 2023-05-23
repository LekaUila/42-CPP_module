/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_function.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:16:03 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/03 16:59:01 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
void write_float(float f)
{
	std::cout << "float: " << f;
	if (f - (int)f == 0 && f < 1000000)
	{
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

void write_double(double d)
{
	std::cout << "double: " << d;
	if (d - (int)d == 0 && d < 1000000)
	{
		std::cout << ".0";
	}
	std::cout << std::endl;
}

void write_char(char c)
{
	if (c > 31 && c < 127)
	{
		std::cout << "char: "<< c << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	
}
