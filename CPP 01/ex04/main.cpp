/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:47:38 by lflandri          #+#    #+#             */
/*   Updated: 2022/12/08 14:46:53 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

//NON FONCTIONNEL


int main(int ac, char **av)
{
	std::string	file;
	char		c;
	std::string	txt = "";
	std::string	old;
	std::string	news;
	size_t		i;
	size_t		j;
	
	if (ac != 4)
	{
		std::cout << "\e[0;31mError : BadNumber of arguments\e[0;m" << std::endl;
		return (1);
	}
	file = av[1];
	news = av[3];
	old = av[2];
	std::ifstream file_input(file.c_str(), std::ios::in);
	if(!file_input.is_open())  
	{
	    std::cout << "\e[0;31mError : Can't Open Input File\e[0;m" << std::endl;
		return (1);
	}
	file += ".replace";
	std::ofstream file_output(file.c_str(), std::ios::out| std::ios::trunc); 
	if(!file_output.is_open())  
	{
		file_input.close();
	    std::cout << "\e[0;31mError : Can't Open Output File\e[0;m" << std::endl;
		return (1);
	}
	while (file_input.get(c))
	{
		txt += c;
	}
	i = 0;
	while (i != txt.size())
	{
		if (txt[i] == *av[2])
		{
			j = i;
			while (txt[j] == av[2][j - i] && av[2][j - i])
			{
				j++;
			}
			if (!av[2][j - i])
			{
				txt.erase(i, old.size());
				txt.insert(i, news);
				i += news.size();
			}
			else
				i++;
		}
		else
			i++;
	}
	file_output << txt;

	file_input.close();
	file_output.close();
}