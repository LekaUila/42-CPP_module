/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:43:09 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/15 11:49:53 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER
# define SCALARCONVERTER
#include <iostream>
#include <string>

int str_to_int(std::string str);
float str_to_float(std::string str);
double str_to_double(std::string str);

int char_to_int(char c);
float char_to_float(char c);
double char_to_double(char c);


char int_to_char(int i);
float int_to_float(int i);
double int_to_double(int i);


char float_to_char(float f);
int float_to_int(float f);
double float_to_double(float f);


void write_float(float f);
void write_double(double d);
void write_char(char c);

char double_to_char(double d);
int double_to_int(double d);
float double_to_float(double d);


class ScalarConverter 
{
private:

	/* data */

protected:

	/* data */

public:

	ScalarConverter(/* args */);					//constructor
	~ScalarConverter();							//destructor
	ScalarConverter (const ScalarConverter &obj);				//copie constructor
	ScalarConverter& operator=(const ScalarConverter& x);		//assignation constructor

	static void convert(std::string);

 
};
#endif
