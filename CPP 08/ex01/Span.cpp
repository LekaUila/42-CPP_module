/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:51:41 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/10 13:35:05 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

bool my_compare (int a, int b)
{
    return (a < b);
}

Span::Span(unsigned int n)
: __size_max(n)
{
}

Span::~Span()
{
}

Span::Span (const Span &obj)
{
	this->__size_max = obj.size_max();
	std::list<int> *objlist = reinterpret_cast< std::list<int> *>(obj.contentKey());
	for (std::list<int>::const_iterator it = objlist->begin(); it != objlist->end(); it++)
		this->__list.push_back(*it);
}
Span& Span::operator=(const Span& x)
{
	this->__size_max = x.size_max();
	std::list<int> *objlist = reinterpret_cast< std::list<int> *>(x.contentKey());
	this->__list.clear();
	for (std::list<int>::const_iterator it = objlist->begin(); it != objlist->end(); it++)
		this->__list.push_back(*it);
	return (*this);
}

unsigned int Span::size_max() const
{
	return (this->__size_max);
}

long unsigned int Span::contentKey() const
{
	return (reinterpret_cast< long unsigned int > (&(this->__list)));
}

void Span::addNumber(int i)
{
	if (this->__size_max < this->__list.size() + 1)
		throw Span::TooManyNumber();
	this->__list.push_back(i);
}

unsigned int Span::shortestSpan()
{
	unsigned int size_l = this->__list.size();
	if (size_l < 2)
		throw std::logic_error("Need more value to find an awsers.");
	this->__list.sort(my_compare);
	unsigned int shortestvalue = -1;
	std::list<int> tempo_list;
	int before = this->__list.front();
	this->__list.pop_front();
	for (unsigned int i = 0; i < size_l - 1; i++)
	{
		if ((unsigned int)(this->__list.front() - before) < shortestvalue)
			shortestvalue = this->__list.front() - before;
		tempo_list.push_back(before);
		before = this->__list.front();
		this->__list.pop_front();
	}
	tempo_list.push_back(before);
	for (unsigned int i = 0; i < size_l; i++)
	{
		this->__list.push_back(tempo_list.front());
		tempo_list.pop_front();
	}
	return (shortestvalue);
}
unsigned int Span::longestSpan()
{
	if (this->__list.size() < 2)
		throw std::logic_error("Need more value to find an awsers.");
	this->__list.sort(my_compare);
	return ( (this->__list.back()) - (this->__list.front()));
}

void Span::addRangeOfNumber(long int deb, long int end, int foot)
{
	if ((deb <= end && foot > 0))
	{
		for (long int i = deb; i < end; i+= foot)
			this->addNumber(i);
	}
	else if ((deb >= end && foot < 0))
	{
		for (long int i = deb; i > end; i+= foot)
			this->addNumber(i);
	}
	
	else
		throw std::invalid_argument("Span::addRangeOfNumber error : this argument can create an error.");
}
