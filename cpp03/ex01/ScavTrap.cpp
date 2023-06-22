/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:39:17 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/22 09:46:27 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPts = 10;
	this->_maxHitPts = 10;
	this->_energy = 10;
	this->_maxEnergy = 10;
	this->_atkDmg = 0;
	std::cout << "ScavTrap " << name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap(scavtrap)
{
	*this = scavtrap;
	std::cout << "ScavTrap " << this->getName() << " has been copied" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& scavtrap)
{
	if (this != &scavtrap)
	{
		this->_name = scavtrap.getName();
		this->_hitPts = scavtrap.getHitPts();
		this->_maxHitPts = scavtrap.getMaxHitPts();
		this->_energy = scavtrap.getEnergy();
		this->_maxEnergy = scavtrap.getMaxEnergy();
		this->_atkDmg = scavtrap.getAtkDmg();
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
		std::cout << "ScavTrap " << this->getName() << " has been destroyed" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " has entered Gatekeeper Mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPts() == 0 && this->getEnergy() == 0)
		return ;
	this->_energy -= this->getAtkDmg();
	std::cout << "ScavTrap " << this->getName() << " attacks " << target \
	<< " causing " << this->getAtkDmg() << " points of damage!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPts() == 0)
		return ;
	if (this->getEnergy() < (int)amount)
	{
		std::cout << "ScavTrap " << this->getName() << " doesn't have enough energy to repair itself" << std::endl;
		return ;
	}
	if (this->getHitPts() + (int)amount > this->getMaxHitPts())
	{
		std::cout << "ScavTrap " << this->getName() << " repaired itself for " << this->getMaxHitPts() - this->getHitPts() \
		<< " hit points" << std::endl;
		this->_hitPts = this->getMaxHitPts();
		this->_energy -= (this->getMaxHitPts() - this->getHitPts());
		return ;
	}
	this->_hitPts += amount;
	this->_energy -= amount;
	std::cout << "ScavTrap " << this->getName() << " repaired itself for " << amount << " hit points" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPts() == 0)
		return ;
	this->_hitPts -= amount;
	std::cout << "ScavTrap " << this->getName() << " has taken " << amount << " points of damage!" << std::endl;
	if (this->getHitPts() < 0)
	{
		this->_hitPts = 0;
		std::cout << "ScavTrap " << this->getName() << " died!" << std::endl;
	}
}