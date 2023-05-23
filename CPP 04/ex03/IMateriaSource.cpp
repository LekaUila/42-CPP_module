/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:34:42 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/31 14:39:51 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(/* args */)
{
}

IMateriaSource::~IMateriaSource()
{
}

IMateriaSource::IMateriaSource (const IMateriaSource &obj)
{
	(void) obj;
}
IMateriaSource& IMateriaSource::operator=(const IMateriaSource& x)
{
	(void) x;
	return (*this);
}
