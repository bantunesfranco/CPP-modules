/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bruno <bruno@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 09:37:36 by bruno         #+#    #+#                 */
/*   Updated: 2023/06/15 20:07:29 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class   Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void 	error( void );
	
	public:
		Harl();
		~Harl();
		void	filter(std::string level);
		void	complain(std::string level);
};

#endif
