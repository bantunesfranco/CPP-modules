/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/20 12:45:16 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 13:44:48 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	this->_count = 0;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_materia[i])
			delete this->_materia[i];
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& src)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
			if (this->_materia[i])
				delete this->_materia[i];
		this->_count = src._count;
		for (int i = 0; i < 4; i++)
			this->_materia[i] = src._materia[i];
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (this->_count < 4)
	{
		std::cout << "MateriaSource learns " << materia->getType() << std::endl;
		this->_materia[this->_count] = materia;
		this->_count++;
	}
	else
		std::cout << "MateriaSource is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
		{
			return (this->_materia[i]->clone());
		}
	}
	std::cout << "Unknown materia" << std::endl;
	return (NULL);
}
