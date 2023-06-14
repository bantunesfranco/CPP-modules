/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 14:43:29 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/14 16:38:11 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed	_x;
		Fixed	_y;
	
	public:
		Point();
		Point(float const x, float const y);
		Point(const Point &Point);
		~Point();
		
		Point&	operator=(const Point &point);
		
		void	setX(float const x);
		void	setY(float const y);
		float	getX(void) const;
		float	getY(void) const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream&	operator<<(std::ostream& out, const Point& point);

#endif
