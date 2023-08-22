/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:48:27 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/22 15:35:29 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME
# define PMERGEME
# include <vector>
# include <deque>
# include <iostream>
# include <stdlib.h>
# include <sys/time.h>
typedef struct timeval	t_time;

class PmergeMe 
{
private:

	/* data */

protected:

	/* data */
	PmergeMe(/* args */);					//constructor
	static void sort_litle_vector(std::vector<int> & vect);
	// static void binary_search_add_rec(std::vector<int> & vect, int to_add, int min, int max);
	static void insert(std::vector<int> & vect, std::vector<int> & tempo1, std::vector<int> & tempo2);
	static void sort_litle_deque(std::deque<int> & vect);
	static void insert(std::deque<int> & vect, std::deque<int> & tempo1, std::deque<int> & tempo2);

public:


	~PmergeMe();							//destructor
	static void sort_vector(std::vector<int> & vect);
	// static void binary_search_add(std::vector<int> & vect, int to_add);
	static void print_content_vector(std::vector<int> & vect);
	static void sort_deque(std::deque<int> & vect);
	static void print_content_deque(std::deque<int> & vect);
 
};
#endif
