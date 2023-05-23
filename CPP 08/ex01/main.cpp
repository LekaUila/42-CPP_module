/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:50:05 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/10 13:39:06 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span lol = Span(10000);
	lol.addRangeOfNumber(0, 10000, 1);
	std::cout << lol.shortestSpan() << std::endl;
	std::cout << lol.longestSpan() << std::endl;

	Span lol2 = Span(10000);
	lol2.addRangeOfNumber(0, 10000, 2);
	std::cout << lol2.shortestSpan() << std::endl;
	std::cout << lol2.longestSpan() << std::endl;
	lol2.addRangeOfNumber(10000, 20000, 2);
	std::cout << lol2.shortestSpan() << std::endl;
	std::cout << lol2.longestSpan() << std::endl;
	
	Span lol3 = Span(10000);
	lol3.addRangeOfNumber(100000, 0, -10);
	std::cout << lol3.shortestSpan() << std::endl;
	std::cout << lol3.longestSpan() << std::endl;

	try
	{
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		lol3.addRangeOfNumber(100000, 0, -10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span crash = Span(5);
		std::cout << crash.shortestSpan() << std::endl;
		std::cout << crash.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}