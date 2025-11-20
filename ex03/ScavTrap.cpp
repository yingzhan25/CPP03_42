/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:49:44 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/19 17:23:11 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor with parameter called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing ";
		std::cout << _attackDamage << " points of damage!" << "(EnergyPoint -1)" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints == 0)
		std::cout << "ScavTrap cannot attack because is dead already!" << std::endl;
	else
		std::cout << "No EnergyPoint left for attack!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (_hitPoints > 0 && _energyPoints > 0)
		std::cout << "ScavTrap " << _name << " is now in guard keeper mode!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << "ScavTrap cannnot guard gate because is dead already!" << std::endl;
	else
		std::cout << "No EnergyPoint left for guard keeper mode!" << std::endl;
}