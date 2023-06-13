/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 09:16:23 by bruno         #+#    #+#                 */
/*   Updated: 2023/06/13 20:27:45 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &point);
		~Fixed();
		
		Fixed&	operator=(const Fixed& point);
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	operator+(const Fixed& point) const;
		Fixed	operator-(const Fixed& point) const;
		Fixed	operator*(const Fixed& point) const;
		Fixed	operator/(const Fixed& point) const;
		Fixed	operator%(const Fixed& point) const;

		bool	operator==(const Fixed& point) const;
		bool	operator!=(const Fixed& point) const;
		bool	operator<=(const Fixed& point) const;
		bool	operator>=(const Fixed& point) const;
		bool	operator<(const Fixed& point) const;
		bool	operator>(const Fixed& point) const;

		int		getRawBits() const;
		void	setRawBits(int const raw);
		
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& point);

#endif
