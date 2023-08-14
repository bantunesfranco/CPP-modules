/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:16 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/14 14:43:53 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal()
{
	*this = dog;
	std::cout << "Dog copy constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog default destructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& dog)
{
	if (this != &dog)
		this->_type = dog.getType();
	std::cout << "Dog assignment operator" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}
