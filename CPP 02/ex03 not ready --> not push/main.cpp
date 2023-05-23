/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:57:15 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/18 12:10:04 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Point z(a,b);
Point h(Fixed( 5.05f ) , Fixed( 2 ));
std::cout << z << std::endl;
std::cout << h << std::endl;
z = h;
std::cout << z << std::endl;
return 0;
}