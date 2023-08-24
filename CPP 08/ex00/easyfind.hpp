/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:18:34 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/24 11:07:00 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>



template < typename T >
bool easyfind( T const & container, int to_find)
{
	typename T::const_iterator i = std::find(container.begin(), container.end(), to_find);
	return (i != container.end());
}
