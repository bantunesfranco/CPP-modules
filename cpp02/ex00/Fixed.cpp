/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruno <bruno@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 09:16:25 by bruno         #+#    #+#                 */
/*   Updated: 2023/06/15 16:11:17 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &point)
{
	this->_value = point.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& point)
{
	if (this != &point)
		this->_value = point.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
