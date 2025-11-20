/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:27:26 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/20 11:33:19 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\033[32m" << "=======Derived: Constructors and operator assignment========" << "\033[0m" << std::endl;

	FragTrap	FragA("Robot1");
	FragTrap	FragB(FragA);
	FragTrap	FragC;
	ClapTrap*	FragD = new FragTrap("Robot2");

	FragC = FragA;
	FragA.displayInfo();
	FragB.displayInfo();
	FragC.displayInfo();
	FragD->displayInfo();

	std::cout << "\033[32m" << "====================Derived: Normal case====================" << "\033[0m" << std::endl;
	FragA.attack("Enemy1");
	FragA.takeDamage(40);
	FragA.beRepaired(30);
	FragA.highFivesGuys();
	FragA.displayInfo();

	std::cout << "\033[32m" << "====================Derived: Polymorphism====================" << "\033[0m" << std::endl;
	FragD->attack("Enemy2");
	FragD->takeDamage(60);
	FragD->beRepaired(55);
	FragD->displayInfo();
	delete FragD;

	std::cout << "\033[32m" << "==========================Destructor==========================" << "\033[0m" << std::endl;
	return (0);
}
