/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 18:41:42 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/04 08:16:40 by bfranco       ########   odam.nl         */
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
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 1000; i++)
		this->_floor[i] = NULL;
	*this = src;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < this->_floorSize; i++)
	{
		if (this->_floor[i] != NULL)
		{
			delete this->_floor[i];
			this->_floor[i] = NULL;
		}
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
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			if (src._inventory[i] != NULL)
				this->_inventory[i] = src._inventory[i]->clone();
		}
		// this->_floor = new AMateria*[src._floorSize];
		for (int i = 0; i < this->_floorSize; i++)
		{
			if (this->_floor[i] != NULL)
			{
				delete this->_floor[i];
				this->_floor[i] = NULL;
			}
			if (src._floor[i] != NULL)
				this->_floor[i] = src._floor[i]->clone();
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
	this->_addToFloor(this->_inventory[idx]);
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

// void	Character::_floorResize(int newSize)
// {
// 	AMateria** newFloor = static_cast<AMateria**>(new AMateria*[newSize]);
// 	for (int i = 0; i < newSize; i++)
// 		newFloor[i] = NULL;
// 	for (int i = 0; i < this->_floorSize; i++)
// 		newFloor[i] = this->_floor[i];
// 	delete[] this->_floor;
// 	this->_floor = newFloor;
// }

void	Character::_addToFloor(AMateria* m)
{
	for (int i = 0; i < this->_floorSize; i++)
	{
		if (this->_floor[i] == NULL)
		{
			this->_floor[i] = m;
			this->_floorSize++;
			return ;
		}
	}
	// this->_floorResize(this->_floorSize + 1);
	// this->_addToFloor(m);
}
