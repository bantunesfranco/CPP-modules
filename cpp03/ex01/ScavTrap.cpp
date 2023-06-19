/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:39:17 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/19 10:18:03 by bfranco       ########   odam.nl         */
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

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap(scavtrap.getName())
{
	*this = scavtrap;
}

// ScavTrap&	ScavTrap::operator=(const ScavTrap& scavtrap)
// {
// 	if (this != &scavtrap)
// 	{
// 		this->_name = scavtrap.getName();
// 		this->_hitPts = scavtrap.getHitPts();
// 		this->_maxHitPts = scavtrap.getMaxHitPts();
// 		this->_energy = scavtrap.getEnergy();
// 		this->_maxEnergy = scavtrap.getMaxEnergy();
// 		this->_atkDmg = scavtrap.getAtkDmg();
// 	}
// 	return (*this);
// }

ScavTrap::~ScavTrap()
{
		std::cout << "ScavTrap " << this->getName() << " has been destryed" << std::endl;
}