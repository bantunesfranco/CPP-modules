/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 15:41:05 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/10 20:16:48 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		std::string	getName(void);
		void		setName(std::string name);
		void		announce( void );
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif