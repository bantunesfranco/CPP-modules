/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 18:30:41 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 13:49:48 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(Cure const& src) : AMateria()
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure&	Cure::operator=(Cure const& src)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

AMateria*	Cure::clone() const
{
	AMateria* newMateria = new Cure();
	return (newMateria);
}
