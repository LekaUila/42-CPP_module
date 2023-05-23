/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:01:14 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/15 11:05:24 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

Serializer::Serializer(/* args */)
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer (const Serializer &obj)
{
	(void) obj;
}
Serializer& Serializer::operator=(const Serializer& x)
{
	(void) x;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast< uintptr_t > (ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast< Data * > (raw);
}