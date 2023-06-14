/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 14:43:26 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/14 15:07:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// default constructor
Point::Point()
{
	this->setX(0f);
	this->sexY(0f);
	// std::cout << "Default constructor called" << std::endl;
}

// float contructor
Point::Point(float const x, float const y)
{
	this->setX(x);
	this->sexY(x);
	// std::cout << "Int constructor called" << std::endl;
}

// copy constructor
Point::Point(Point& const point)
{
	*this = point;
	// std::cout << "Copy constructor called" << std::endl;
}

// Destructor
Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

// getter member func
float	Point::getX() const
{
	return (this->_x.toFloat());
}

float	Point::getY() const
{
	return (this->_y.toFloat());
}

// setter member func
void	Point::setX(float const x)
{
	this->_x = Fixed(x);
}

void	Point::setY(float const y)
{
	this->_y = Fixed(y);
}