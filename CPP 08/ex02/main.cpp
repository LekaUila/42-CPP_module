/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:43:40 by lflandri          #+#    #+#             */
/*   Updated: 2023/08/08 21:24:26 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main(void)
{
std::cout << "MutanStack :" << std::endl;

MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);

std::cout << "list :" << std::endl;

std::list<int> l1;
l1.push_back(5);
l1.push_back(17);
std::cout << l1.back() << std::endl;
l1.pop_back();
std::cout << l1.size() << std::endl;
l1.push_back(3);
l1.push_back(5);
l1.push_back(737);
//[...]
l1.push_back(0);
std::list<int>::iterator itl = l1.begin();
std::list<int>::iterator itel = l1.end();
++itl;
--itl;
while (itl != itel)
{
std::cout << *itl << std::endl;
++itl;
}
std::list<int> l2(l1);

MutantStack<int>	stack;

std::cout << (stack.begin() == stack.end()) << std::endl;

	return (0);
}