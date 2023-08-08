/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:31:54 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/08 16:23:18 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw std::invalid_argument("Error: could not open file.");
    	BitcoinExchange btc;

        if (SHOW_DATA)
            btc.printData();
        btc.exchange(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

	return (0);
}