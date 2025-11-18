/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:49:44 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/18 16:59:40 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : _name("Default"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor with parameter called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called" << std::endl;
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
		std::cout << "ScavTrap is dead already!" << std::endl;
	else
		std::cout << "No EnergyPoint left for attack!" << std::endl;
}