/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:48:27 by lflandri          #+#    #+#             */
/*   Updated: 2023/10/20 18:11:22 by lflandri         ###   ########.fr       */
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
	static std::vector<int> sort_vector_rec(std::vector<std::vector<int> > & vect);
	static std::deque<int> sort_deque_rec(std::deque<std::deque<int> > & vect);

public:


	~PmergeMe();							//destructor
	static void sort_vector(std::vector<int> & vect);
	// static void binary_search_add(std::vector<int> & vect, int to_add);
	static void print_content_vector(std::vector<int> & vect);
	static void sort_deque(std::deque<int> & vect);
	static void print_content_deque(std::deque<int> & vect);
 
};
#endif
