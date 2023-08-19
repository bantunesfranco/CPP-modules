/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:28:02 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/19 16:15:23 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) , FragTrap(name), ScavTrap(name)
{
	this->setRealName(name);
	this->setHitPts(FragTrap::_hitPts);
	this->setMaxHitPts(FragTrap::_maxHitPts);
	this->setEnergy(ScavTrap::_energy);
	this->setMaxEnergy(ScavTrap::_maxEnergy);
	this->setAtkDmg(FragTrap::_atkDmg);
	this->setName(name + "_clap_name");
	std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap) : ClapTrap(diamondtrap), FragTrap(diamondtrap), ScavTrap(diamondtrap)
{
	std::cout << "DiamondTrap copy constructor" << std::endl;
	*this = diamondtrap;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& diamondtrap)
{
	if (this != &diamondtrap)
	{
		this->_name = diamondtrap.getRealName();
		this->_hitPts = diamondtrap._hitPts;
		this->_maxHitPts = diamondtrap._maxHitPts;
		this->_energy = diamondtrap._energy;
		this->_maxEnergy = diamondtrap._maxEnergy;
		this->_atkDmg = diamondtrap._atkDmg;
		this->setName(diamondtrap.getName());
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am DiamondTrap " << this->getRealName() << " and ClapTrap " << this->getName() << std::endl;
}

void		DiamondTrap::setRealName(std::string name)
{
	this->_name = name;
}

std::string		DiamondTrap::getRealName(void) const
{
	return (this->_name);
}
