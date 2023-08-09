/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 10:15:22 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/09 16:42:16 by bfranco       ########   odam.nl         */
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
	std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	std::cout << "ClapTrap copy constructor" << std::endl;
	*this = claptrap;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "ClapTrap assignment operator" << std::endl;
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
	std::cout << "ClapTrap default destructor" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPts == 0)
		return ;
	std::cout << "ClapTrap " << this->_name;
	if (this->_energy == 0)
	{
		std::cout << " is out of energy!" << std::endl;
		return ;
	}
	this->_energy -= 1;
	std::cout << " attacks " << target << " causing " << this->_atkDmg << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int	diff = this->_maxHitPts - this->_hitPts;
	if (this->_hitPts == 0 || diff == 0)
		return ;
	std::cout << "ClapTrap " << this->_name;
	if (this->_energy == 0)
	{
		std::cout << " is out of energy!" << std::endl;
		return ;
	}
	this->_energy -= 1;
	if (this->_hitPts + (int)amount > this->_maxHitPts)
		amount = diff;
	this->_hitPts += amount;
	std::cout << " repaired itself for " << amount << " hit points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPts == 0)
		return ;
	this->_hitPts -= amount;
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage!" << std::endl;
	if (this->_hitPts < 0)
	{
		this->_hitPts = 0;
		std::cout << "ClapTrap " << this->_name << " died!" << std::endl;
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
	if (hitPts > this->_maxHitPts)
		this->setMaxHitPts(hitPts);
}

void	ClapTrap::setMaxHitPts(int hitPts)
{
	this->_maxHitPts = hitPts;
}

void	ClapTrap::setEnergy(int energy)
{
	this->_energy = energy;
	if (energy > this->_maxEnergy)
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
