/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 08:26:47 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/17 11:19:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name) , _weapon(weapon)
{
	std::cout << this->_name << " was born" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " died in battle" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
