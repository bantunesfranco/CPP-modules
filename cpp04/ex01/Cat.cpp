/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:11 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/12 12:44:37 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat.getType())
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
		this->_brain = new Brain(*dog._brain)
	}
	std::cout << "Cat assignment operator" << std::endl;
	return (*this);
}
void	Cat::makeSound(void) const
{
	std::cout << "Miau Miau" << std::endl;
}
