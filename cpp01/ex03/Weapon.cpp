/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 08:27:04 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/11 13:47:46 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

void	Weapon::setType( std::string type) 
{
	this->_type = type;
}

std::string	Weapon::getType() const
{
	return (this->_type);
}
