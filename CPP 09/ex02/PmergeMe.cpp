/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:48:22 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/22 14:14:35 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"


PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::sort_litle_vector(std::vector<int> & vect)
{
	int tempo;
	
	if (vect[0] > vect[1])
	{
		tempo = vect[0];

		vect[0] = vect[1];
		vect[1] = tempo;
	}
}

void PmergeMe::sort_litle_deque(std::deque<int> & vect)
{
	int tempo;
	
	if (vect[0] > vect[1])
	{
		tempo = vect[0];

		vect[0] = vect[1];
		vect[1] = tempo;
	}
}

void PmergeMe::sort_vector(std::vector<int> & vect)
{
	std::vector<int> tempo1;
	std::vector<int> tempo2;

	if (vect.size() < 2)
	{
		return ;
	}
	if (vect.size() == 2)
	{
		PmergeMe::sort_litle_vector(vect);
		return ;
	}
	else
	{
		for (size_t i = 0; i < vect.size(); i++)
		{
			if (i < vect.size() / 2)
				tempo1.push_back(vect[i]);
			else
				tempo2.push_back(vect[i]);
		}
		PmergeMe::sort_vector(tempo1);
		PmergeMe::sort_vector(tempo2);
	}
	vect.clear();
	PmergeMe::insert(vect, tempo1, tempo2);
}

void PmergeMe::sort_deque(std::deque<int> & vect)
{
	std::deque<int> tempo1;
	std::deque<int> tempo2;

	if (vect.size() < 2)
	{
		return ;
	}
	if (vect.size() == 2)
	{
		PmergeMe::sort_litle_deque(vect);
		return ;
	}
	else
	{
		for (size_t i = 0; i < vect.size(); i++)
		{
			if (i < vect.size() / 2)
				tempo1.push_back(vect[i]);
			else
				tempo2.push_back(vect[i]);
		}
		PmergeMe::sort_deque(tempo1);
		PmergeMe::sort_deque(tempo2);
	}
	vect.clear();
	PmergeMe::insert(vect, tempo1, tempo2);
}

void PmergeMe::insert(std::vector<int> & vect, std::vector<int> & tempo1, std::vector<int> & tempo2)
{
	size_t ind1 = 0;
	size_t ind2 = 0;

	while (ind1 < tempo1.size() || ind2 < tempo2.size())
	{
		if (ind1 >= tempo1.size())
		{
			vect.push_back(tempo2[ind2]);
			ind2++;
		}
		else if (ind2 >= tempo2.size())
		{
			vect.push_back(tempo1[ind1]);
			ind1++;
		}
		else
		{
			if (tempo1[ind1] >= tempo2[ind2])
			{
				vect.push_back(tempo2[ind2]);
				ind2++;
			}
			else
			{
				vect.push_back(tempo1[ind1]);
				ind1++;
			}
		}
	}
}

void PmergeMe::insert(std::deque<int> & vect, std::deque<int> & tempo1, std::deque<int> & tempo2)
{
	size_t ind1 = 0;
	size_t ind2 = 0;

	while (ind1 < tempo1.size() || ind2 < tempo2.size())
	{
		if (ind1 >= tempo1.size())
		{
			vect.push_back(tempo2[ind2]);
			ind2++;
		}
		else if (ind2 >= tempo2.size())
		{
			vect.push_back(tempo1[ind1]);
			ind1++;
		}
		else
		{
			if (tempo1[ind1] >= tempo2[ind2])
			{
				vect.push_back(tempo2[ind2]);
				ind2++;
			}
			else
			{
				vect.push_back(tempo1[ind1]);
				ind1++;
			}
		}
	}
}

// void PmergeMe::binary_search_add_rec(std::vector<int> & vect, int to_add, int min, int max)
// {
// 	const int mid = (max - min) / 2 + min;
// 	if (max - min == 0)
// 	{
// 		vect.insert(vect.begin(), mid);
// 		return ;
// 	}
// 	if (vect[mid] > to_add)
// 		binary_search_add_rec(vect, to_add, min, mid);
// 	else
// 		binary_search_add_rec(vect, to_add, mid, max);
// }

// void PmergeMe::binary_search_add(std::vector<int> & vect, int to_add)
// {
// 	binary_search_add_rec(vect, to_add, 0, vect.size() - 1);
// }

void PmergeMe::print_content_vector(std::vector<int> & vect)
{
	for (size_t i = 0; i < vect.size(); i++)
	{
		if (i < vect.size() - 1)
			std::cout << vect[i] << " ";
		else
			std::cout << vect[i] << std::endl;
	}
}

void PmergeMe::print_content_deque(std::deque<int> & vect)
{
	for (size_t i = 0; i < vect.size(); i++)
	{
		if (i < vect.size() - 1)
			std::cout << vect[i] << " ";
		else
			std::cout << vect[i] << std::endl;
	}
}
