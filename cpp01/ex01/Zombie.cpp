/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 15:41:42 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/13 19:14:48 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	std::cout << "A zombie rose from it's grave" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << this->getName() << " rose from it's grave!!!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->getName() << " got it's head blown off!!!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string	const& Zombie::getName(void)
{
	return (this->_name);
}