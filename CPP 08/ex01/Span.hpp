/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:50:46 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/10 12:00:13 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN
# define SPAN
#include <iostream>
#include <list>
class Span 
{
private:

	class TooManyNumber : public std::logic_error
	{
	
	public:
		TooManyNumber()
		: std::logic_error::logic_error("There are too many number in the Span class.")
		{}
	};

	
	std::list<int> __list;
	unsigned int __size_max;

protected:

	/* data */

public:

	Span(unsigned int n);				//constructor
	~Span();							//destructor
	Span (const Span &obj);				//copie constructor
	Span& operator=(const Span& x);		//assignation constructor

	unsigned int size_max() const;
	long unsigned int contentKey() const;

	void addNumber(int i);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void addRangeOfNumber(long int deb, long int end, int foot);
 
};
#endif
