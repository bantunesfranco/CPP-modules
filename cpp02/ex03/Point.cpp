/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 14:43:26 by bfranco       #+#    #+#                 */
/*   Updated: 2024/06/12 15:56:28 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// default constructor
Point::Point() : _x(0.f), _y(0.f)
{
	// std::cout << "Default constructor called" << std::endl;
}

// float contructor
Point::Point(float const x, float const y) : _x(x), _y(y)
{
	// std::cout << "Int constructor called" << std::endl;
}

// copy constructor
Point::Point(const Point &point): _x(point._x), _y(point._y)
{
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
	// std::cout << "Copy assignment operator called" << std::endl;
	(void)point;
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
	bool	collinear = (ab == 0 && bc == 0 && ca == 0);

	return (pos != neg && !collinear);
}
