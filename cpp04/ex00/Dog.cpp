/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:16 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 18:18:02 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog.getType())
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
	std::cout << "Dog copy constructor" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}
