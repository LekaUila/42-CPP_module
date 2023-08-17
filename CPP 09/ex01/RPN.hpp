/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:56:12 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/17 11:58:25 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_
# define RPN_
# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# define __STDC_LIMIT_MACROS
# include <stdint.h>
class RPN 
{
private:

	RPN(/* args */);					//constructor

protected:

	/* data */

public:


	~RPN();							//destructor

	static std::string nb_to_string(long int nb);
	static int isOperator(char c);
	static bool isNumber(char c);
	static void can_do_operation(std::stack<int> &number_stack, char c, size_t i);
	static void imposible_operation(long int n1, long int n2, char c, std::string str, size_t i);
	static void show_operation(long int n1, long int n2, char c, long int result);
	static void rpnSystem(std::string str, bool show_details);
 
};
#endif
