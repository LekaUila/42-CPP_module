/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:43:12 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/15 13:39:49 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter (const ScalarConverter &obj)
{
	(void) obj;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& x)
{
	(void) x;
	return (*this);
}

static	int isNumber(char c)
{
	return (c >= 48 && c <= 57);
}

static int type_finder(std::string str)
{
	if (str == "nan" || str == "nanf" || str.length() == 0)
		return 0;
	if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
		return 5;
	if (str == "-inf" || str == "-inff")
		return 6;
	if (str.length() == 1)
	{
		int c = str.at(0);
		if ((c > -1 && c < 48) || (c > 57 && c < 127))
			return (1);
	}
	long unsigned int i = 0;
	while (i != str.length())
	{
		if (!((str.at(i) >= 9 && str.at(i) <= 13) || str.at(i) == ' '))
			break;
		i++;
	}
	if (str.at(i) == '+' || str.at(i) == '-')
	{
		i++;
	}
	int add = 0;
	while (i != str.length())
	{
		if (isNumber(str.at(i)))
			i++;
		else
		{
			if (!add && str.at(i) == '.')
				add++;
			else if (/*add == 1 && */str.at(i) == 'f' && i == str.length() - 1)
				add = 2;
			else
				return (0);
			i++;
		}
	}
	return (2 + add);
} 

void ScalarConverter::convert(std::string str_convert)
{
		switch (type_finder(str_convert))
		{
		case 0: /*NaN*/
			std::cout << "char: impossible" 
			<< std::endl << "int: impossible" 
			<< std::endl << "float: nanf" 
			<< std::endl << "double: nan" << std::endl;
			break;

		case 1: /*CHAR*/
			write_char(str_convert.at(0));
			std::cout << "int: " << char_to_int(str_convert.at(0)) << std::endl;
			write_float(char_to_float(str_convert.at(0)));
			write_double(char_to_double(str_convert.at(0)));
			break;

		case 2: /*INT*/
		{
			try
			{
				int result = str_to_int(str_convert);
				write_char(int_to_char(result));
				std::cout << "int: " << result << std::endl;
				write_float(int_to_float(result));
				write_double(int_to_double(result));
			}
			catch(const std::exception& e)
			{
				std::cout << "char: Non displayable" << std::endl;
				std::cout << "int: " << e.what() << std::endl;
				try
				{
					write_float(str_to_float(str_convert));
				}
				catch(const std::exception& e_bis)
				{
					std::cout << "float: " << e_bis.what() << std::endl;
				}
				try
				{
					write_double(str_to_double(str_convert));
				}
				catch(const std::exception& e_bis)
				{
					std::cout << "double: " << e_bis.what() << std::endl;
				}
			}
			break;
		}

		case 3: /*DOUBLE*/
		{
			try
			{
				double result = str_to_double(str_convert);
				write_char(double_to_char(result));
				try
				{
					std::cout << "int: " << double_to_int(result) << std::endl;
				}
				catch(const std::exception& e_bis)
				{
					std::cout << "int: " << e_bis.what() << std::endl;
				}
				try
				{
					write_float(double_to_float(result));
				}
				catch(const std::exception& e_bis)
				{
					std::cout << "float: " << e_bis.what() << std::endl;
				}
				write_double(result);
			}
			catch(const std::exception& e)
			{
				std::cout << "char: Non displayable" << std::endl;
				std::cout << "int: Int Overflow" << std::endl;
				std::cout << "float: " << e.what() << "f" << std::endl;
				std::cout << "double: "<< e.what() << std::endl;
			}
			break;
		}

		case 4: /*FLOAT*/
		{
			try
			{
				float result = str_to_float(str_convert);
				write_char(float_to_char(result));
				try
				{
					std::cout << "int: " << float_to_int(result) << std::endl;
				}
				catch(const std::exception& e_bis)
				{
					std::cout << "int: " << e_bis.what() << std::endl;
				}
				write_double(float_to_double(result));
				write_float(result);
			}
			catch(const std::exception& e)
			{
				std::cout << "char: Non displayable" << std::endl;
				std::cout << "int: Int Overflow" << std::endl;
				std::cout << "float: " << e.what() << std::endl;
				try
				{
					write_double(str_to_double(str_convert));
				}
				catch(const std::exception& e_bis)
				{
					std::cout << "double: " << e_bis.what() << std::endl;
				}
			}
			break;
		}

		case 5: /*NaN*/
			std::cout << "char: impossible" 
			<< std::endl << "int: Int Overflow"
			<< std::endl << "float: inff" 
			<< std::endl << "double: inf" << std::endl;
			break;

		case 6: /*NaN*/
			std::cout << "char: impossible" 
			<< std::endl << "int: Int Overflow" 
			<< std::endl << "float: -inff" 
			<< std::endl << "double: -inf" << std::endl;
			break;
		
		default:
			break;
		}
}