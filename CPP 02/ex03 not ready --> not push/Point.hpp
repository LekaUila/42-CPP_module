/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:26:41 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/18 11:25:21 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point 
{
private:

	const Fixed x;
	const Fixed y;

public:

	Point(void);					//constructor
	Point(Fixed x, Fixed y);	
	~Point();							//destructor
	Point (const Point &obj);				//copie constructor
	Point& operator=(const Point& x);		//assignation constructor
	friend std::ostream& operator<<(std::ostream &out, const Point &obj);

	const Fixed get_x() const;
	const Fixed get_y() const;

};
