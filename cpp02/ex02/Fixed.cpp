/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 09:16:25 by bruno         #+#    #+#                 */
/*   Updated: 2023/06/15 16:17:10 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

// default constructor
Fixed::Fixed()
{
	this->_value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

// int contructor
Fixed::Fixed(const int i)
{
	this->_value = i * (1 << this->_bits);
	// std::cout << "Int constructor called" << std::endl;
}

// float constructor
Fixed::Fixed(const float f)
{
	this->_value = roundf(f * (1 << this->_bits));
	// std::cout << "Float constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed &point)
{
	*this = point;
	// std::cout << "Copy constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// fixed point to int conversion
int	Fixed::toInt() const
{
	return (this->_value >> this->_bits);
}

// fixed point to float conversion
float	Fixed::toFloat() const
{
	return (this->getRawBits() / (1 << this->_bits));
}

// getter member func
int	Fixed::getRawBits() const
{
	return (this->_value);
}

// setter member func
void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// Copy assignment operator
Fixed&	Fixed::operator=(const Fixed& point)
{
	if (this != &point)
		this->_value = point.getRawBits();
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

// insertion operator overload
std::ostream&	operator<<(std::ostream& out, const Fixed& point)
{
	return (out << point.toFloat());
}


Fixed&	Fixed::max(Fixed& p1, Fixed& p2)
{
	return (p1 > p2 ? p1:p2);
}


const Fixed&	Fixed::max(Fixed const& p1, Fixed const& p2)
{
	return (p1 > p2 ? p1:p2);
}


Fixed&	Fixed::min(Fixed& p1, Fixed& p2)
{
	return (p1 < p2 ? p1:p2);
}


const Fixed&	Fixed::min(Fixed const& p1, Fixed const& p2)
{
	return (p1 < p2 ? p1:p2);
}
