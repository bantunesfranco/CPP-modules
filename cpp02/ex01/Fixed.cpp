/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruno <bruno@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 09:16:25 by bruno         #+#    #+#                 */
/*   Updated: 2023/06/13 17:52:54 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	this->_value = i;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	this->_value = f;
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &point)
{
	this->_value = point.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& point)
{
	if (this != &point)
		this->_value = point.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

// std::ostream&	operator<<(std::ostream& out, const Fixed& point)
// {
// 	out << point.toInt();
// 	return (out);
// }

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt() const
{
	return (this->getRawBits());
}

float	Fixed::toFloat() const
{
	return (this->getRawBits());
}
