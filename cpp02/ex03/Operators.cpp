/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Operators.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 19:25:41 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/14 14:05:30 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// addition operator
Fixed	Fixed::operator+(const Fixed& point) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() + point.getRawBits());
	return (res);
}

// subtraction operator
Fixed	Fixed::operator-(const Fixed& point) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() - point.getRawBits());
	return (res);
}

// mutiplication operator
Fixed	Fixed::operator*(const Fixed& point) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() * point.getRawBits() / (1 << _bits));
	return (res);
}

// division operator
Fixed	Fixed::operator/(const Fixed& point) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() / point.getRawBits());
	return (res);
}

// modulo operator
Fixed	Fixed::operator%(const Fixed& point) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() % point.getRawBits());
	return (res);
}

// pre-incremnt operator
Fixed&	Fixed::operator++(void)
{
	++_value;
	return (*this);
}

// post-decrement operator
Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;
	++_value;
	return (old);
}

// pre-incremnt operator
Fixed&	Fixed::operator--(void)
{
	--_value;
	return (*this);
}

// post-decrement operator
Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;
	--_value;
	return (old);
}

// Comparison operators
bool	Fixed::operator==(const Fixed& point) const
{
	return (this->getRawBits() == point.getRawBits());
}

bool	Fixed::operator!=(const Fixed& point) const
{
	return (!this->operator==(point));
}

bool	Fixed::operator<=(const Fixed& point) const
{
	return (!this->operator>(point));
}

bool	Fixed::operator>=(const Fixed& point) const
{
	return (!this->operator<(point));
}

bool	Fixed::operator<(const Fixed& point) const
{
	return (!this->operator>(point));
}

bool	Fixed::operator>(const Fixed& point) const
{
	return (this->getRawBits() > point.getRawBits());
}
