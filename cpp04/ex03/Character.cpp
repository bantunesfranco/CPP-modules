/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 18:41:42 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/19 19:07:51 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &src)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}
Character& Character::operator=(Character const &src)
{
	std::cout << "Character assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cerr << "Index out of range" << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cerr << "Index out of range" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "Slot is empty" << std::endl;
}