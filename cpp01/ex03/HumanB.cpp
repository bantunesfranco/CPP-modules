/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 08:26:52 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/11 13:34:25 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
	std::cout << this->_name << " was born" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " died in battle" << std::endl;
}

void	HumanB::attack()
{
	if (this->isUnarmed() == true)
		std::cout << this->_name << " is unarmed" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	std::cout << this->_name << " equipped " << this->_weapon->getType() << std::endl;
}

bool	HumanB::isUnarmed()
{
	if (this->_weapon)
		return (false);
	return (true);
}