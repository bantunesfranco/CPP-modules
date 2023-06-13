/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruno <bruno@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 09:16:23 by bruno         #+#    #+#                 */
/*   Updated: 2023/06/13 09:30:10 by bruno         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

class	Fixed
{
	private:
		int					value;
		static const int	bits;
	public:
		Fixed();
		Fixed(const Fixed &point);
		~Fixed();
		int	getRawBits();
		void setRawBits();
	
}