/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 14:43:29 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/14 14:58:13 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	x;
		Fixed const	y;
	
	public:
		Point();
		Point(float const x, float const y);
		Point(Point& const Point);
		~Point();
		
		Point&	operator=(Point& const point);
		
		void	setX(float const x);
		void	setY(float const y);
		float	getX(float const x) const;
		float	getY(float const y) const;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
