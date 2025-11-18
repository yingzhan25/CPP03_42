/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:19:47 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/18 16:02:59 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor with parameter called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
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

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
		std::cout << _attackDamage << " points of damage!" << "(EnergyPoint -1)" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints == 0)
		std::cout << "ClapTrap is dead already!" << std::endl;
	else
		std::cout << "No EnergyPoint left for attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		std::cout << "ClapTrap remain unattacked!" << std::endl;
	else if (amount < _hitPoints)
	{
		std::cout << "ClapTrap " << _name << " is caused " << amount;
		std::cout << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
	else if (amount >= _hitPoints && _hitPoints != 0)
	{
		std::cout << "ClapTrap is attacked to death now!" << std::endl;
		_hitPoints = 0;;
	}
	else
		std::cout << "ClapTrap cannot be attacked because is dead already!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (amount == 0)
		std::cout << "ClapTrap remain unrepaired!" << std::endl;
	else if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " is repaired with ";
		std::cout << amount << " points!" << "(EnergyPoint -1)" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else if (_energyPoints == 0)
		std::cout << "No EnergyPoint left for repairment!" << std::endl;
	else
		std::cout << "ClapTrap cannot be repaired because is dead already!" << std::endl;
}

void	ClapTrap::displayInfo(void)const
{
	std::cout << "\033[33m" << "+++++++++++++++++++Display status++++++++++++++++++" << "\033[0m" << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "HitPoint: " << _hitPoints << std::endl;
	std::cout << "EnergyPoint: " << _energyPoints << std::endl;
	std::cout << "AttackDamage: " << _attackDamage << std::endl;
}