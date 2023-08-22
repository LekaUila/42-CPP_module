/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:36:35 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/22 12:16:51 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename array_type >
void iter(array_type *tab, size_t t, void (*f)(array_type & ))
{
	for (size_t i = 0; i < t; i++)
	{
		f(tab[i]);
	}
	
}