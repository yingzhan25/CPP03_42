/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:27:26 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/20 17:40:30 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\033[32m" << "=======Derived: Constructors and operator assignment========" << "\033[0m" << std::endl;

	DiamondTrap	DiamondA("test");
	std::cout << "\033[31m" << "------------------------------------------------------------" << "\033[0m" << std::endl;
	DiamondTrap	DiamondB(DiamondA);
	std::cout << "\033[31m" << "------------------------------------------------------------" << "\033[0m" << std::endl;
	DiamondTrap	DiamondC;
	std::cout << "\033[31m" << "------------------------------------------------------------" << "\033[0m" << std::endl;

	DiamondC = DiamondA;
	DiamondA.displayInfo();
	DiamondB.displayInfo();
	DiamondC.displayInfo();

	std::cout << "\033[32m" << "====================Derived: Normal case====================" << "\033[0m" << std::endl;
	DiamondA.attack("Enemy");
	DiamondA.takeDamage(40);
	DiamondA.beRepaired(30);
	DiamondA.guardGate();
	DiamondA.highFivesGuys();
	DiamondA.whoAmI();
	DiamondA.displayInfo();

	std::cout << "\033[32m" << "==========================Destructor==========================" << "\033[0m" << std::endl;
	return (0);
}
