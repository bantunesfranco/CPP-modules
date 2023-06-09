/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 10:15:22 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/21 19:36:09 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->_hitPts = 10;
	this->_maxHitPts = 10;
	this->_energy = 10;
	this->_maxEnergy = 10;
	this->_atkDmg = 0;
	std::cout << "ClapTrap " << name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	*this = claptrap;
	std::cout << "ClapTrap " << this->getName() << " has been copied" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& claptrap)
{
	if (this != &claptrap)
	{
		this->_name = claptrap.getName();
		this->_hitPts = claptrap.getHitPts();
		this->_maxHitPts = claptrap.getMaxHitPts();
		this->_energy = claptrap.getEnergy();
		this->_maxEnergy = claptrap.getMaxEnergy();
		this->_atkDmg = claptrap.getAtkDmg();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->getName() << " has been destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->getHitPts() == 0 && this->getEnergy() == 0)
		return ;
	this->_energy -= this->getAtkDmg();
	std::cout << "ClapTrap " << this->getName() << " attacks " << target \
	<< " causing " << this->getAtkDmg() << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPts() == 0)
		return ;
	if (this->getEnergy() < (int)amount)
	{
		std::cout << "ClapTrap " << this->getName() << " doesn't have enough energy to repair itself" << std::endl;
		return ;
	}
	if (this->getHitPts() + (int)amount > this->getMaxHitPts())
	{
		std::cout << "ClapTrap " << this->getName() << " repaired itself for " << this->getMaxHitPts() - this->getHitPts() \
		<< " hit points" << std::endl;
		this->_hitPts = this->getMaxHitPts();
		this->_energy -= (this->getMaxHitPts() - this->getHitPts());
		return ;
	}
	this->_hitPts += amount;
	this->_energy -= amount;
	std::cout << "ClapTrap " << this->getName() << " repaired itself for " << amount << " hit points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPts() == 0)
		return ;
	this->_hitPts -= amount;
	std::cout << "ClapTrap " << this->getName() << " has taken " << amount << " points of damage!" << std::endl;
	if (this->getHitPts() < 0)
	{
		this->_hitPts = 0;
		std::cout << "ClapTrap " << this->getName() << " died!" << std::endl;
	}
}

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

int	ClapTrap::getHitPts() const
{
	return (this->_hitPts);
}

int	ClapTrap::getMaxHitPts() const
{
	return (this->_maxHitPts);
}

int	ClapTrap::getEnergy() const
{
	return (this->_energy);
}

int	ClapTrap::getMaxEnergy() const
{
	return (this->_maxEnergy);
}

int	ClapTrap::getAtkDmg() const
{
	return (this->_atkDmg);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitPts(int hitPts)
{
	this->_hitPts = hitPts;
	if (hitPts > this->getMaxHitPts())
		this->setMaxHitPts(hitPts);
}

void	ClapTrap::setMaxHitPts(int hitPts)
{
	this->_maxHitPts = hitPts;
}

void	ClapTrap::setEnergy(int energy)
{
	this->_energy = energy;
	if (energy > this->getMaxEnergy())
		this->setMaxEnergy(energy);
}

void	ClapTrap::setMaxEnergy(int energy)
{
	this->_maxEnergy = energy;
}

void	ClapTrap::setAtkDmg(int atkDmg)
{
	this->_atkDmg = atkDmg;
}
