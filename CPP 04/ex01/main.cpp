/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:57:15 by lflandri          #+#    #+#             */
/*   Updated: 2023/01/27 16:42:12 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();

delete j;//should not create a leak
delete i;


Dog toutou;
toutou.PrintIdeas();
toutou.SetIdeas(5, "Caresse");
toutou.PrintIdeas();
Dog chienchien(toutou);
chienchien.PrintIdeas();


Cat minet;
minet.PrintIdeas();
minet.SetIdeas(89, "kill all human");
minet.PrintIdeas();
Cat matou;

matou = minet;
matou.PrintIdeas();


return 0;
}
