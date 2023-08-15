/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_function.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:12:54 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/15 13:45:19 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include <float.h>

int str_to_int(std::string str)
{
	long int ret = 0;
	int sign = 1;
	long unsigned int i = 0;
	while (i != str.length())
	{
		if (!((str.at(i) >= 9 && str.at(i) <= 13) || str.at(i) == ' '))
			break;
		i++;
	}
	if (str.at(i) == '+' || str.at(i) == '-')
	{
		if (str.at(i) == '-')
			sign = -1;
		i++;
	}
	while (i != str.length())
	{
		ret = ret * 10 + str.at(i) - 48;
		if (ret * sign > INT32_MAX || ret * sign < INT32_MIN)
			throw std::invalid_argument("Int OverFlow");
		i++;
	}
	return (ret * sign);
}

float str_to_float(std::string str)
{
	double ret = 0.0;
	double ret_b = 0.0;
	double sign = 1.0;
	long unsigned int i = 0;
	while (i != str.length())
	{
		if (!((str.at(i) >= 9 && str.at(i) <= 13) || str.at(i) == ' '))
			break;
		i++;
	}
	if (str.at(i) == '+' || str.at(i) == '-')
	{
		if (str.at(i) == '-')
			sign = -1;
		i++;
	}
	while (str.at(i) != '.')
	{
		ret = ret * 10 + str.at(i) - 48;
		if (ret * sign < FLT_MAX * -1)					//old value FLT_MIN
			throw std::invalid_argument("-inff");
		if (ret * sign > FLT_MAX)
			throw std::invalid_argument("inff");
		i++;
		if (i == str.length() || str.at(i) == 'f')
		{
			return ((ret + ret_b) * sign);
		}
	}
	i = str.length() - 1;
	while (str.at(i) != '.')
	{
		if (str.at(i) == 'f')
		{
			i--;
		}
		ret_b = ret_b * 0.1 + (str.at(i) - 48) * 0.1;
		if ((ret + ret_b) * sign < FLT_MAX * -1)
			throw std::invalid_argument("-inff");
		if ((ret + ret_b) * sign > FLT_MAX)
			throw std::invalid_argument("inff");
		i--;
	}
	return ((ret + ret_b) * sign);
}

double str_to_double(std::string str)
{
	long double ret = 0.0L;
	long double ret_b = 0.0L;
	long double sign = 1.0L;
	long unsigned int i = 0;
	while (i != str.length())
	{
		if (!((str.at(i) >= 9 && str.at(i) <= 13) || str.at(i) == ' '))
			break;
		i++;
	}
	if (str.at(i) == '+' || str.at(i) == '-')
	{
		if (str.at(i) == '-')
			sign = -1;
		i++;
	}
	while (str.at(i) != '.')
	{
		ret = ret * 10 + str.at(i) - 48;
		if (ret * sign < 1.797693e+308 * -1)				//old value 2.225074e-308
			throw std::invalid_argument("-inf");
		if (ret * sign > 1.797693e+308)
			throw std::invalid_argument("inf");
		i++;
		if (i == str.length())
		{
			return ((ret + ret_b) * sign);
		}
	}
	i = str.length() - 1;
	while (str.at(i) != '.')
	{
		if (str.at(i) == 'f')
		{
			i--;
		}
		ret_b = ret_b * 0.1 + (str.at(i) - 48) * 0.1;
		if ((ret + ret_b) * sign < 1.797693e+308 * -1)
			throw std::invalid_argument("-inf");
		if ((ret + ret_b) * sign > 1.797693e+308)
			throw std::invalid_argument("inf");
		i--;
	}
	return ((ret + ret_b) * sign);
}

int char_to_int(char c)
{
	return (static_cast<int> (c));
}

float char_to_float(char c)
{
	return (static_cast<float>(c));
}

double char_to_double(char c)
{
	return (static_cast<double> (c));
}

char int_to_char(int i)
{
	if ( 127 < i || i < 0)
		return(-1);
	return (static_cast<char> (i));
}

float int_to_float(int i)
{

	return (static_cast<float>(i));
}

double int_to_double(int i)
{
	return (static_cast<double> (i));
}

char float_to_char(float f)
{
	if ( 127 < f || f < 0)
		return (-1);
	return (static_cast<char> (f));
}

int float_to_int(float f)
{
	if (static_cast<double>(INT32_MAX) < f || f < static_cast<double>(INT32_MIN))
		throw std::invalid_argument("Int OverFlow");
	return (static_cast<int> (f));
}

double float_to_double(float f)
{
	return (static_cast<double> (f));
}

char double_to_char(double d)
{
	if ( 127 < d || d < 0)
		return (-1);
	return (static_cast<char> (d));
}

int double_to_int(double d)
{
	if (INT32_MAX < d || d < INT32_MIN)
		throw std::invalid_argument("Int OverFlow");
	return (static_cast<int> (d));
}

float double_to_float(double d)
{
	return (static_cast<float> (d));
}