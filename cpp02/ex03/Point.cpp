/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 14:43:26 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/14 16:37:27 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// default constructor
Point::Point()
{
	this->setX(0.0f);
	this->setY(0.0f);
	// std::cout << "Default constructor called" << std::endl;
}

// float contructor
Point::Point(float const x, float const y)
{
	this->setX(x);
	this->setY(y);
	// std::cout << "Int constructor called" << std::endl;
}

// copy constructor
Point::Point(const Point &point)
{
	*this = point;
	// std::cout << "Copy constructor called" << std::endl;
}

// Destructor
Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

// Assignment operator overload
Point&	Point::operator=(const Point& point)
{
	if (this != &point)
	{
		this->_x = point.getX();
		this->_y = point.getY();
	}
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
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

// insertion operator overload
std::ostream&	operator<<(std::ostream& out, const Point& point)
{
	return (out << "(" << point.getX() << "," << point.getY() << ")");
}