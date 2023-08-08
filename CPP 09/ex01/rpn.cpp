/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:09:08 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/08 20:27:14 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# define __STDC_LIMIT_MACROS
# include <stdint.h>

static std::string nb_to_string(long int nb)
{
	return (static_cast<std::ostringstream*>( &(std::ostringstream() << nb) )->str());
}

static int isOperator(char c)
{
	return (c =='-' || c =='/' || c =='*' || c =='+');
}

static bool isNumber(char c)
{
	return (c - '0' >= 0 && c - '0' <= 9);
}
static void can_do_operation(std::stack<int> &number_stack, char c, size_t i)
{
	if (number_stack.size() < 2)
	{
		std::string err_str = "Error : can't do \"";
		err_str += c;
		err_str += "\" operation at ";
		err_str += nb_to_string(i + 1);
		err_str += " col because there are not enough numbers in the stack.";
		throw std::invalid_argument(err_str);
	}
}

static void imposible_operation(long int n1, long int n2, char c, std::string str, size_t i)
{
	std::string err_str = "Error : can't do \"";
	err_str += nb_to_string(n1);
	err_str += " ";
	err_str += c;
	err_str += " ";
	err_str += nb_to_string(n2);
	err_str += "\" operation at ";
	err_str += nb_to_string(i + 1);
	err_str += " col because ";
	err_str += str;
	throw std::invalid_argument(err_str);
}

static void show_operation(long int n1, long int n2, char c, long int result)
{
	std::string str = "";
	str += nb_to_string(n1);
	str += " ";
	str += c;
	str += " ";
	str += nb_to_string(n2);
	str += " = ";
	str += nb_to_string(result);

	std::cout << str << std::endl;
}

static void rpnSystem(std::string str, bool show_details)
{
	std::stack<int> number_stack;

	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str.at(i);
		if (c != ' ')
		{
			if (isNumber(c))
				number_stack.push((int) (c - '0'));
			else if (isOperator(c))
			{
				switch ((c))
				{
				case '+':
				{
					can_do_operation(number_stack, c, i);
					long int n2 = (long int) number_stack.top();
					number_stack.pop();
					long int n1 = (long int) number_stack.top();
					number_stack.pop();
					long int result = n1 + n2;
					if ((long int) INT32_MAX < result || (long int) INT32_MIN > result)
						imposible_operation(n1, n2, c, "an overflow as occured.", i );
					if (show_details)
						show_operation(n1, n2, c, result);
					number_stack.push(result);
					break;
					}
				case '-':
				{
					can_do_operation(number_stack, c, i);
					long int n2 = (long int) number_stack.top();
					number_stack.pop();
					long int n1 = (long int) number_stack.top();
					number_stack.pop();
					long int result = n1 - n2;
					if ((long int) INT32_MAX < result || (long int) INT32_MIN > result)
						imposible_operation(n1, n2, c, "an overflow as occured.", i );
					if (show_details)
						show_operation(n1, n2, c, result);
					number_stack.push(result);
					break;
				}
				case '/':
				{
					can_do_operation(number_stack, c, i);
					long int n2 = (long int) number_stack.top();
					number_stack.pop();
					long int n1 = (long int) number_stack.top();
					number_stack.pop();
					if (n2 == 0)
						imposible_operation(n1, n2, c, "an division by 0 as occured.", i );
					long int result = n1 / n2;
					if ((long int) INT32_MAX < result || (long int) INT32_MIN > result)
						imposible_operation(n1, n2, c, "an overflow as occured.", i );
					if (show_details)
						show_operation(n1, n2, c, result);
					number_stack.push(result);
					break;
				}
				case '*':
				{
					can_do_operation(number_stack, c, i);
					long int n2 = (long int) number_stack.top();
					number_stack.pop();
					long int n1 = (long int) number_stack.top();
					number_stack.pop();
					long int result = n1 * n2;
					if ((long int) INT32_MAX < result || (long int) INT32_MIN > result)
						imposible_operation(n1, n2, c, "an overflow as occured.", i );
					if (show_details)
						show_operation(n1, n2, c, result);
					number_stack.push(result);
					break;
				}

				default:
					throw std::invalid_argument("Error : An impossible situation has occured : Check that your are always in the good reality.");
					break;
				}
			}
			else
			{
				std::string err_str = "Error : Unknow character \"";
				err_str += c;
				err_str += "\" at ";
				err_str += nb_to_string(i + 1);
				err_str += " col.";
				throw std::invalid_argument(err_str);
			}
		}
	}
	if (number_stack.size() > 1)
		throw std::invalid_argument("Error : The stack has more than one element at the end of the calcul : Check your calculation.");
	std::cout << "Result of your calculation : \e[1;32m" << number_stack.top() << "\e[0;m" << std::endl;
	
	
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error : No Calculation to do : " << std::endl 
			<< "here is a reminder of use : ./RPN \"\e[1;34myour_calculation\e[0;m\" \"\e[1;34mshow_calculation : \e[0;32myes\e[1;34m or \e[0;31mno\e[1;34m (default : \e[0;31mno\e[1;34m)\e[0;m\"" << std::endl
			<< "\e[0;33m\e[1mStoping execution\e[25m\e[0;m" << std::endl; 
		return (1);
	}
	else if (ac > 3)
	{
		std::cout << "Error : Invalid number of parameter :" << std::endl 
			<< "here is a reminder of use : ./RPN \"\e[1;34myour_calculation\e[0;m\" \"\e[1;34mshow_calculation : \e[0;32myes\e[1;34m or \e[0;31mno\e[1;34m (default : \e[0;31mno\e[1;34m)\e[0;m\"" << std::endl
			<< "\e[0;33m\e[1mStoping execution\e[25m\e[0;m" << std::endl; 
		return (1);
	}
	else
	{
		try
		{
			bool show_detail = false;
			if (ac == 3)
			{
				if ("yes" == (std::string) av[2])
					show_detail = true;
				std::cout << "show calculation : " << (show_detail ? "\e[0;32myes\e[0;m" : "\e[0;31mno\e[0;m") << std::endl;
			}
			rpnSystem(av[1], show_detail);
				
		}
		catch(const std::exception& e)
		{
			std::cerr << "\e[0;31m\e[5m"  << e.what() << "\e[25m\e[0;m" << '\n';
		}
		
	}
	std::cout << "\e[0;33m\e[1mStoping execution\e[25m\e[0;m" << std::endl; 
	return (0);  
}