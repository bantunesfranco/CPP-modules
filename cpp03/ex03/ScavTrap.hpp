/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:39:19 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/09 17:23:23 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class	ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap& scavtrap);
		
		ScavTrap& operator=(const ScavTrap& scavtrap);

		void guardGate();
		void attack(const std::string& target);
};

#endif
