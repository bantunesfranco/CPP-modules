/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:39:17 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/17 12:11:46 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPts = 100;
	this->_maxHitPts = 100;
	this->_energy = 100;
	this->_maxEnergy = 100;
	this->_atkDmg = 30;
	std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap) : ClapTrap(fragtrap)
{
	std::cout << "FragTrap copy constructor" << std::endl;
	*this = fragtrap;
}

FragTrap&	FragTrap::operator=(const FragTrap& fragtrap)
{
	if (this != &fragtrap)
	{
		this->_name = fragtrap.getName();
		this->_hitPts = fragtrap.getHitPts();
		this->_maxHitPts = fragtrap.getMaxHitPts();
		this->_energy = fragtrap.getEnergy();
		this->_maxEnergy = fragtrap.getMaxEnergy();
		this->_atkDmg = fragtrap.getAtkDmg();
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default destructor" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " high fives everyone!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_hitPts == 0 && this->_energy == 0)
		return ;
	this->_energy -= this->_atkDmg;
	std::cout << "FragTrap " << this->_name << " attacks " << target \
	<< " causing " << this->_atkDmg << " points of damage!" << std::endl;
}
