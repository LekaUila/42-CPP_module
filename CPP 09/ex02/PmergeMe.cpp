/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:48:22 by lflandri          #+#    #+#             */
/*   Updated: 2023/10/20 18:14:40 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"


PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::~PmergeMe()
{
}


//###################### VECTOR

static int find_min_for_max_vector(std::vector<std::vector<int> > & vect, int max)
{
	int min = 2147483647;
	int ind = -1;
	
	for (size_t i = 0; i < vect.size(); i++)
	{
		if (vect[i][1] == max && vect[i][0] < min)
		{
			min = vect[i][0];
			ind = i;			
		}
	}
	return (ind);
}

static	void binary_insert_vector(std::vector<int> & vect, int min, int max, int to_insert)
{
	int middle = (max - min) / 2 + min;
	if (max - min <= 1)
	{
		if (vect[min] > to_insert)
			vect.insert(vect.begin() + min, to_insert);
		else
			vect.insert(vect.begin() + min + 1, to_insert);
	}
	else if (vect[middle] == to_insert)
	{
		vect.insert(vect.begin() + middle, to_insert);
	}
	else if (vect[middle] > to_insert)
	{
		binary_insert_vector(vect, min, middle, to_insert);
	}
	else if (vect[middle] < to_insert)
	{
		binary_insert_vector(vect, middle, max, to_insert);
	}
}

static void mix_vector(std::vector<std::vector<int> > & vect, int nb1, int nb2, int last)
{	
	int middle = nb1 * 2 + nb2;
	int max = middle + last;
	if (max >  (int) vect.size())
	{
		max = (int) vect.size();
		middle = max - last;
	}
	int ind = 0;
	while (last + ind < max - (middle) / 2 && last + ind < (int) vect.size() && max - ind - 1 < (int) vect.size())
	{	std::vector<int> tempo = vect[last + ind];
		vect[last + ind] = vect[max - ind - 1];
		vect[max - ind - 1] = tempo;
		ind++;
	}
	if (last + ind < (int) vect.size() && max - ind - 1 < (int) vect.size())
	{
		mix_vector(vect, nb2, middle, last + ind + 1);
	}
}

static std::vector<int> vector_sorting(std::vector<std::vector<int> > & vect)
{
	std::vector<int>	final_vector;
	size_t ind;

	for (size_t i = 0; i < vect.size(); i++)
	{
		final_vector.push_back(vect[i][1]);
	}
	PmergeMe::sort_vector(final_vector);
	mix_vector(vect, 1, 0, 0);
	ind = find_min_for_max_vector(vect, final_vector[0]);
	final_vector.insert(final_vector.begin(), vect[ind][0]);
	for (size_t i = 0; i < vect.size(); i++)
	{
		if (ind != i)
		{
			binary_insert_vector(final_vector, 0, final_vector.size(), vect[i][0]);
		}
	}
	return (final_vector);
}

std::vector<int> PmergeMe::sort_vector_rec(std::vector<std::vector<int> > & vect)
{
	std::vector<std::vector<int> > main_vec;
	if (vect[0].size() < 2)
	{
		for (size_t i = 0; i + 1 < vect.size(); i+=2)
		{
			std::vector<int> vect1;
			if (vect[i][0] > vect[i + 1][0])
			{
				vect1.push_back(vect[i + 1][0]);
				vect1.push_back(vect[i][0]);
			}
			else
			{
				vect1.push_back(vect[i][0]);				
				vect1.push_back(vect[i + 1][0]);
			}
			main_vec.push_back(vect1);
		}
		std::vector<int> final_vector;
		final_vector = vector_sorting(main_vec);
		if (vect.size() % 2)
		{
			binary_insert_vector(final_vector, 0, final_vector.size(), vect[vect.size() - 1][0]);
		}
	
		return (final_vector);
	}
	for (size_t i = 0; i < vect.size(); i++)
	{
		if (vect[i].size() > 1)
		{
			std::vector<int> vect1;
			std::vector<int> vect2;
			for (size_t j = 0; j < vect[i].size() / 2; j++)
			{
				vect1.push_back(vect[i][j]);
				if (vect[i].size() / 2 + j != vect[i].size())
				{
					vect2.push_back(vect[i][j + vect[i].size() / 2]);
				}
			}
			main_vec.push_back(vect1);
			main_vec.push_back(vect2);
			if (vect[i].size() % 2 )
			{
				std::vector<int> vect_spe;
				vect_spe.push_back(vect[i][vect[i].size() - 1]);
				main_vec.push_back(vect_spe);
			}
		}
		else
		{
			main_vec.push_back(vect[i]);
		}
	}
	return (sort_vector_rec(main_vec));
}

void PmergeMe::sort_vector(std::vector<int> & vect)
{
	if (vect.size() < 2)
		return ;
	std::vector<std::vector<int> > main_vec;
	main_vec.push_back(vect);
	vect = PmergeMe::sort_vector_rec(main_vec);
}




//################################ DEQUE



static int find_min_for_max(std::deque<std::deque<int> > & vect, int max)
{
	int min = 2147483647;
	int ind = -1;
	
	for (size_t i = 0; i < vect.size(); i++)
	{
		if (vect[i][1] == max && vect[i][0] < min)
		{
			min = vect[i][0];
			ind = i;			
		}
	}
	return (ind);
}

static	void binary_insert_deque(std::deque<int> & vect, int min, int max, int to_insert)
{
	int middle = (max - min) / 2 + min;
	if (max - min <= 1)
	{
		if (vect[min] > to_insert)
			vect.insert(vect.begin() + min, to_insert);
		else
			vect.insert(vect.begin() + min + 1, to_insert);
	}
	else if (vect[middle] == to_insert)
	{
		vect.insert(vect.begin() + middle, to_insert);
	}
	else if (vect[middle] > to_insert)
	{
		binary_insert_deque(vect, min, middle, to_insert);
	}
	else if (vect[middle] < to_insert)
	{
		binary_insert_deque(vect, middle, max, to_insert);
	}
}

static void mix_deque(std::deque<std::deque<int> > & vect, int nb1, int nb2, int last)
{	
	int middle = nb1 * 2 + nb2;
	int max = middle + last;
	if (max >  (int) vect.size())
	{
		max = (int) vect.size();
		middle = max - last;
	}
	int ind = 0;
	while (last + ind < max - (middle) / 2 && last + ind < (int) vect.size() && max - ind - 1 < (int) vect.size())
	{	std::deque<int> tempo = vect[last + ind];
		vect[last + ind] = vect[max - ind - 1];
		vect[max - ind - 1] = tempo;
		ind++;
	}
	if (last + ind < (int) vect.size() && max - ind - 1 < (int) vect.size())
	{
		mix_deque(vect, nb2, middle, last + ind + 1);
	}
}

static std::deque<int> deque_sorting(std::deque<std::deque<int> > & vect)
{
	std::deque<int>	final_vector;
	size_t ind;

	for (size_t i = 0; i < vect.size(); i++)
	{
		final_vector.push_back(vect[i][1]);
	}
	PmergeMe::sort_deque(final_vector);
	mix_deque(vect, 1, 0, 0);
	ind = find_min_for_max(vect, final_vector[0]);
	final_vector.insert(final_vector.begin(), vect[ind][0]);
	for (size_t i = 0; i < vect.size(); i++)
	{
		if (ind != i)
		{
			binary_insert_deque(final_vector, 0, final_vector.size(), vect[i][0]);
		}
	}
	return (final_vector);
}




std::deque<int> PmergeMe::sort_deque_rec(std::deque<std::deque<int> > & vect)
{
	std::deque<std::deque<int> > main_vec;
	if (vect[0].size() < 2)
	{
		for (size_t i = 0; i + 1 < vect.size(); i+=2)
		{
			std::deque<int> vect1;
			if (vect[i][0] > vect[i + 1][0])
			{
				vect1.push_back(vect[i + 1][0]);
				vect1.push_back(vect[i][0]);
			}
			else
			{
				vect1.push_back(vect[i][0]);				
				vect1.push_back(vect[i + 1][0]);
			}
			main_vec.push_back(vect1);
		}
		std::deque<int> final_vector;
		final_vector = deque_sorting(main_vec);
		if (vect.size() % 2)
		{
			binary_insert_deque(final_vector, 0, final_vector.size(), vect[vect.size() - 1][0]);
		}
	
		return (final_vector);
	}
	for (size_t i = 0; i < vect.size(); i++)
	{
		if (vect[i].size() > 1)
		{
			std::deque<int> vect1;
			std::deque<int> vect2;
			for (size_t j = 0; j < vect[i].size() / 2; j++)
			{
				vect1.push_back(vect[i][j]);
				if (vect[i].size() / 2 + j != vect[i].size())
				{
					vect2.push_back(vect[i][j + vect[i].size() / 2]);
				}
			}
			main_vec.push_back(vect1);
			main_vec.push_back(vect2);
			if (vect[i].size() % 2 )
			{
				std::deque<int> vect_spe;
				vect_spe.push_back(vect[i][vect[i].size() - 1]);
				main_vec.push_back(vect_spe);
			}
		}
		else
		{
			main_vec.push_back(vect[i]);
		}
	}
	return (sort_deque_rec(main_vec));
}

void PmergeMe::sort_deque(std::deque<int> & vect)
{
	if (vect.size() < 2)
		return ;
	std::deque<std::deque<int> > main_vec;
	main_vec.push_back(vect);
	vect = PmergeMe::sort_deque_rec(main_vec);
}


//###################### print function


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