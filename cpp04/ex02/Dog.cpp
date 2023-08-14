/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:16 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/13 20:19:46 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : AAnimal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& dog) : AAnimal(dog.getType())
{
	*this = dog;
	std::cout << "Dog copy constructor" << std::endl;
}

Dog::~Dog(void)
{
	if (this->_brain)
		delete this->_brain;
	std::cout << "Dog default destructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& dog)
{
	if (this != &dog)
	{
		this->_type = dog.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*dog._brain);
	}
	std::cout << "Dog assignment operator" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}

void	Dog::setIdea(std::string idea)
{
	static int i = 0;
	if (i >= 100)
	{
		std::cout << "Brain is full of ideas" << std::endl;
		return ;
	}
	this->_brain->_ideas[i] = idea;
	i++;
}