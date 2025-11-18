/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:27:26 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/18 15:43:54 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\033[32m" << "=======Constructors and operator assignment========" << "\033[0m" << std::endl;

	ClapTrap	clapA("Jim");
	ClapTrap	clapB(clapA);
	ClapTrap	clapC;

	clapC = clapA;
	clapA.displayInfo();
	clapB.displayInfo();
	clapC.displayInfo();

	std::cout << "\033[32m" << "====================Normal case====================" << "\033[0m" << std::endl;
	clapA.attack("Enemy1");
	clapA.takeDamage(5);
	clapA.beRepaired(3);
	clapA.displayInfo();

	std::cout << "\033[32m" << "===========Edge case: Attacked to death============" << "\033[0m" << std::endl;
	clapB.attack("Enemy2");
	clapB.takeDamage(11);
	clapB.beRepaired(3);
	clapB.displayInfo();

	std::cout << "\033[32m" << "=============Edge case: No energy left=============" << "\033[0m" << std::endl;
	for (size_t i = 0; i < 11; i++)
		clapC.attack("Enemy3");
	clapC.takeDamage(5);
	clapC.beRepaired(3);
	clapC.displayInfo();

	std::cout << "\033[32m" << "=====================Destructor====================" << "\033[0m" << std::endl;
	return (0);
}
