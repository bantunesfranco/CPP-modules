/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruno <bruno@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 09:16:25 by bruno         #+#    #+#                 */
/*   Updated: 2023/06/13 09:35:24 by bruno         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &point);
{
	this->value = point->value;
	std::cout << "Copy constructor called" << std::endl;

}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}