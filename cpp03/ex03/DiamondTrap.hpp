/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:24:29 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/09 17:27:09 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class	ScavTrap : public FragTrap, public ScavTrap
{
	private:
		_name;

	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& diamondtrap);
		
		DiamondTrap& operator=(const DiamondTrap& diamondtrap);

		void guardGate();
		void attack(const std::string& target);
};

#endif