/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:43:53 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/18 11:25:18 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

Point::Point()
: x(0), y(0)
{
}

Point::Point(Fixed x, Fixed y)
: x(x), y(y)
{
}

Point::~Point()
{
}

Point::Point (const Point &obj)
: x(obj.x), y(obj.y)
{
}

Point& Point::operator=(const Point& obj)
{
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Point &obj)
{
	out << "(" << obj.get_x() << ", " << obj.get_y() << ")";
	return out;
}


const Fixed Point::get_x() const
{
	return (this->x);
}

const Fixed Point::get_y() const
{
	return (this->y);
}

