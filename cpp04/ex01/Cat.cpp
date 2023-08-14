/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:11 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/14 15:29:51 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal()
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

void	Cat::getIdeas(void) const
{
	for (int i = 0; i < 100; i++)
	{
		const std::string	idea = this->_brain->getIdea(i);
		if (idea.length() == 0)
			continue ;
		std::cout << "Idea " << i << " is: \"" << idea << "\" at the address " << this->_brain->getIdeaAddress(i) << std::endl;
	}
}

void	Cat::setIdea(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}