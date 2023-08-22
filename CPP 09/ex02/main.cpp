/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:47:02 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/22 16:00:36 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned long int	ft_gettime(t_time timep)
{
	t_time				time;
	unsigned long int	pr_time;
	unsigned long int	pr_time_bis;

	gettimeofday(&time, NULL);
	pr_time_bis = ((time.tv_usec - timep.tv_usec) );
	pr_time =  pr_time_bis;
	return (pr_time);
}

static int	ft_iswhitespace(int c)
{
	if (c == 32 || (8 < c && c < 14))
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (47 < c && c < 58)
		return (1);
	return (0);
}

static int	ft_check_letter(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (-1);
		str++;
	}
	return (0);
}

int	ft_atoiwo(char *str, int *n)
{
	int				sign;
	long long int	nb;

	nb = 0;
	sign = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*(str++) == 45)
			sign = -1;
	}
	if (ft_check_letter(str))
		return (-1);
	while (*str > 47 && *str < 58)
	{
		nb = (nb * 10) + (*str - 48);
		str++;
		if (nb * sign > 2147483647 || nb * sign < -2147483648)
			return (-1);
	}
	*n = nb;
	return (0);
}

int main(int ac, char **av)
{
	std::vector<int> vect;
	std::deque<int> deq;
	t_time	start;
	unsigned long int endt;
	

	for (int i = 1; i < ac; i++)
	{
		int nb = 0;
		if (ft_atoiwo(av[i], &nb))
		{
			std::cout << "Error bad input : " << av[i] << std::endl;
			return (1);
		}
		vect.push_back(nb);
		deq.push_back(nb);
	}

	gettimeofday(&start, NULL);
	//std::cout << start.tv_usec << std::endl;
	PmergeMe::sort_vector(vect);
	endt = ft_gettime(start);

	
	std::cout << "sorted in " << endt << " μs." << std::endl;
	PmergeMe::print_content_vector(vect);

	gettimeofday(&start, NULL);
	PmergeMe::sort_deque(deq);
	endt = ft_gettime(start);

	std::cout << "sorted : " << endt << " μs." << std::endl;
	PmergeMe::print_content_deque(deq);

	return (0);
};