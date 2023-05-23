/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:30:35 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 12:05:39 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain 
{
private:

	std::string ideas[100];

public:

	Brain(/* args */);					//constructor
	~Brain();							//destructor
	Brain (const Brain &obj);				//copie constructor
	Brain& operator=(const Brain& x);		//assignation constructor
	void	PrintIdeas() const;
	void	SetIdeas(unsigned int ind, std::string ideas);
};

#endif