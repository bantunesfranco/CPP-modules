/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:24:29 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 09:26:53 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
		int			_hitPts;
		int			_maxHitPts;
		int			_energy;
		int			_maxEnergy;
		int			_atkDmg;

	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& diamondtrap);
		
		DiamondTrap& operator=(const DiamondTrap& diamondtrap);

		void		whoAmI(void);
		void		attack(const std::string& target);
		std::string	getRealName(void) const;
		void		setRealName(std::string name);
};

#endif