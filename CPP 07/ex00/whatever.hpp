/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:48:25 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/22 12:16:27 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename typ >
void swap(typ & a, typ & b)
{
	typ tempo;
	tempo = a;
	a = b;
	b = tempo;
}

template< typename typ >
typ const & max(typ const & a, typ const & b)
{
	return (a > b ? a : b);
}

template< typename typ >
typ const & min(typ const & a, typ const & b)
{
	return (a < b ? a : b);
}