/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:18:34 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/09 15:48:50 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>



template < typename T >
int easyfind( T const & container, int to_find)
{
	int count = 0;
	for ( typename T::const_iterator i = container.begin(); i != container.end(); i++)
	{
		if (*i == to_find)
			return (count);
		count++;
	}
	return(-1);
}
