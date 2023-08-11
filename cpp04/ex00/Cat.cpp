/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:11 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 18:18:23 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat.getType())
{
	*this = cat;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& cat)
{
	if (this != &cat)
		this->_type = cat.getType();
	std::cout << "Cat copy constructor" << std::endl;
	return (*this);
}
void	Cat::makeSound(void) const
{
	std::cout << "Miau Miau" << std::endl;
}
