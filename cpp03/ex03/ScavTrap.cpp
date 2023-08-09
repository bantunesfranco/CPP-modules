/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:39:17 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/09 16:44:39 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPts = 100;
	this->_maxHitPts = 100;
	this->_energy = 50;
	this->_maxEnergy = 50;
	this->_atkDmg = 20;
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap(scavtrap)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
	*this = scavtrap;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& scavtrap)
{
	std::cout << "ScavTrap assignment operator" << std::endl;
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
	std::cout << "ScavTrap default destructor" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " has entered Gatekeeper Mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPts == 0 && this->_energy == 0)
		return ;
	this->_energy -= this->_atkDmg;
	std::cout << "ScavTrap " << this->_name << " attacks " << target \
	<< " causing " << this->_atkDmg << " points of damage!" << std::endl;
}

