/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:16 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/14 16:24:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : AAnimal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& dog) : AAnimal()
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
		this->_brain = new Brain(*dog._brain);
	}
	std::cout << "Dog assignment operator" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}

void	Dog::getIdeas(void) const
{
	for (int i = 0; i < 100; i++)
	{
		const std::string	idea = this->_brain->getIdea(i);
		if (idea.length() == 0)
			continue ;
		std::cout << "Idea " << i << " is: \"" << idea << "\" at the address " << this->_brain->getIdeaAddress(i) << std::endl;
	}
}

void	Dog::setIdea(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}