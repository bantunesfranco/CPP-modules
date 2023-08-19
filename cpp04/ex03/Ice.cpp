/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 18:21:26 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/19 19:21:06 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const& src) : AMateria()
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice&	Ice::operator=(Ice const& src)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

Ice*	Ice::clone() const
{
	return (new Ice(*this));
}
