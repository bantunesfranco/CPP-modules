/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongWrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 18:51:57 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 18:56:58 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal string constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal)
{
	*this = wronganimal;
	std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal default destructor" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& wronganimal)
{
	if (this != &wronganimal)
		this->_type = wronganimal.getType();
	std::cout << "WrongAnimal copy constructor" << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*random wronganimal noises*" << std::endl;
}
