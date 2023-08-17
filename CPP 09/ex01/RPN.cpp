/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:56:09 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/17 12:00:53 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

RPN::RPN(/* args */)
{
}

RPN::~RPN()
{
}

std::string RPN::nb_to_string(long int nb)
{
	return (static_cast<std::ostringstream*>( &(std::ostringstream() << nb) )->str());
}

int  RPN::isOperator(char c)
{
	return (c =='-' || c =='/' || c =='*' || c =='+');
}

bool RPN::isNumber(char c)
{
	return (c - '0' >= 0 && c - '0' <= 9);
}
void RPN::can_do_operation(std::stack<int> &number_stack, char c, size_t i)
{
	if (number_stack.size() < 2)
	{
		std::string err_str = "Error : can't do \"";
		err_str += c;
		err_str += "\" operation at ";
		err_str += RPN::nb_to_string(i + 1);
		err_str += " col because there are not enough numbers in the stack.";
		throw std::invalid_argument(err_str);
	}
}

void RPN::imposible_operation(long int n1, long int n2, char c, std::string str, size_t i)
{
	std::string err_str = "Error : can't do \"";
	err_str += RPN::nb_to_string(n1);
	err_str += " ";
	err_str += c;
	err_str += " ";
	err_str += RPN::nb_to_string(n2);
	err_str += "\" operation at ";
	err_str += RPN::nb_to_string(i + 1);
	err_str += " col because ";
	err_str += str;
	throw std::invalid_argument(err_str);
}

void RPN::show_operation(long int n1, long int n2, char c, long int result)
{
	std::string str = "";
	str += RPN::nb_to_string(n1);
	str += " ";
	str += c;
	str += " ";
	str += RPN::nb_to_string(n2);
	str += " = ";
	str += RPN::nb_to_string(result);

	std::cout << str << std::endl;
}

void RPN::rpnSystem(std::string str, bool show_details)
{
	std::stack<int> number_stack;

	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str.at(i);
		if (c != ' ')
		{
			if (RPN::isNumber(c))
				number_stack.push((int) (c - '0'));
			else if (RPN::isOperator(c))
			{
				switch ((c))
				{
				case '+':
				{
					RPN::can_do_operation(number_stack, c, i);
					long int n2 = (long int) number_stack.top();
					number_stack.pop();
					long int n1 = (long int) number_stack.top();
					number_stack.pop();
					long int result = n1 + n2;
					if ((long int) INT32_MAX < result || (long int) INT32_MIN > result)
						RPN::imposible_operation(n1, n2, c, "an overflow as occured.", i );
					if (show_details)
						RPN::show_operation(n1, n2, c, result);
					number_stack.push(result);
					break;
					}
				case '-':
				{
					RPN::can_do_operation(number_stack, c, i);
					long int n2 = (long int) number_stack.top();
					number_stack.pop();
					long int n1 = (long int) number_stack.top();
					number_stack.pop();
					long int result = n1 - n2;
					if ((long int) INT32_MAX < result || (long int) INT32_MIN > result)
						RPN::imposible_operation(n1, n2, c, "an overflow as occured.", i );
					if (show_details)
						RPN::show_operation(n1, n2, c, result);
					number_stack.push(result);
					break;
				}
				case '/':
				{
					RPN::can_do_operation(number_stack, c, i);
					long int n2 = (long int) number_stack.top();
					number_stack.pop();
					long int n1 = (long int) number_stack.top();
					number_stack.pop();
					if (n2 == 0)
						RPN::imposible_operation(n1, n2, c, "an division by 0 as occured.", i );
					long int result = n1 / n2;
					if ((long int) INT32_MAX < result || (long int) INT32_MIN > result)
						RPN::imposible_operation(n1, n2, c, "an overflow as occured.", i );
					if (show_details)
						RPN::show_operation(n1, n2, c, result);
					number_stack.push(result);
					break;
				}
				case '*':
				{
					RPN::can_do_operation(number_stack, c, i);
					long int n2 = (long int) number_stack.top();
					number_stack.pop();
					long int n1 = (long int) number_stack.top();
					number_stack.pop();
					long int result = n1 * n2;
					if ((long int) INT32_MAX < result || (long int) INT32_MIN > result)
						RPN::imposible_operation(n1, n2, c, "an overflow as occured.", i );
					if (show_details)
						RPN::show_operation(n1, n2, c, result);
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
	if (number_stack.size() == 0)
		throw std::invalid_argument("Error : The stack is empty.");
	std::cout << "Result of your calculation : \e[1;32m" << number_stack.top() << "\e[0;m" << std::endl;
	
	
}
