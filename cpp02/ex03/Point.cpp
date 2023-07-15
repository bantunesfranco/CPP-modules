/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 14:43:26 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/15 10:33:30 by bfranco       ########   odam.nl         */
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

// bsp function
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ab = Fixed(b.getX() - a.getX()) * Fixed(point.getY() - a.getY()) - Fixed(b.getY() - a.getY()) * Fixed(point.getX() - a.getX());
	Fixed	bc = Fixed(c.getX() - b.getX()) * Fixed(point.getY() - b.getY()) - Fixed(c.getY() - b.getY()) * Fixed(point.getX() - b.getX());
	Fixed	ca = Fixed(a.getX() - c.getX()) * Fixed(point.getY() - c.getY()) - Fixed(a.getY() - c.getY()) * Fixed(point.getX() - c.getX());
	
	// std::cout << "ab: " << ab << std::endl;
	// std::cout << "bc: " << bc << std::endl;
	// std::cout << "ca: " << ca << std::endl;

	bool	pos = (ab > 0 && bc > 0 && ca > 0);
	bool	neg = (ab < 0 && bc < 0 && ca < 0);

	std::cout << "pos: " << pos << std::endl;
	std::cout << "neg: " << neg << std::endl;
	
	return ((pos && !neg) || (!pos && neg));
}