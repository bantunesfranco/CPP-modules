/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:11 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/13 20:19:43 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : AAnimal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& cat) : AAnimal(cat.getType())
{
	*this = cat;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat(void)
{
	if (this->_brain)
		delete this->_brain;
	std::cout << "Cat default destructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& cat)
{
	if (this != &cat)
	{
		this->_type = cat.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*cat._brain);
	}
	std::cout << "Cat assignment operator" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miau Miau" << std::endl;
}

void	Cat::setIdea(std::string idea)
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