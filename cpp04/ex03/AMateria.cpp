/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 16:21:23 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/19 18:28:09 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("default")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(AMateria const& src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria&	AMateria::operator=(AMateria const& src)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	else
		std::cout << "This materia is not valid" << std::endl;
}
