/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruno <bruno@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 09:16:23 by bruno         #+#    #+#                 */
/*   Updated: 2023/06/13 14:58:31 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &point);
		~Fixed();
		Fixed& operator=(const Fixed& point);
		int	getRawBits() const;
		void setRawBits(int const raw);
};

#endif
