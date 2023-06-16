/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 09:18:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/16 12:51:25 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTTRAP_HPP
#define CLAPTTRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitPts;
		int			_maxHitPts;
		int			_energy;
		int			_maxEnergy;
		int			_atkDmg;
		
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& claptrap);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& claptrap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
		std::string	getName() const;
		int			getHitPts() const;
		int			getMaxHitPts() const;
		int			getEnergy() const;
		int			getMaxEnergy() const;
		int			getAtkDmg() const;
		void		setName(std::string name);
		void		setHitPts(int hitPts);
		void		setMaxHitPts(int hitPts);
		void		setEnergy(int energy);
		void		setMaxEnergy(int energy);
		void		setAtkDmg(int atkDmg);
};

#endif
