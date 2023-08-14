/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:07 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/14 16:21:52 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal default constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& aanimal)
{
	*this = aanimal;
	std::cout << "AAnimal copy constructor" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal default destructor" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& aanimal)
{
	if (this != &aanimal)
		this->_type = aanimal.getType();
	std::cout << "AAnimal assignment operator" << std::endl;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::setType(std::string type)
{
	this->_type = type;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "*random aanimal noises*" << std::endl;
}
