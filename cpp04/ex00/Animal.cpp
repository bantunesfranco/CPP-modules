/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:07 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/14 15:16:11 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal& animal)
{
	*this = animal;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal default destructor" << std::endl;
}

Animal&	Animal::operator=(const Animal& animal)
{
	if (this != &animal)
		this->_type = animal.getType();
	std::cout << "Animal assignment operator" << std::endl;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(std::string type)
{
	this->_type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << "*random animal noises*" << std::endl;
}
