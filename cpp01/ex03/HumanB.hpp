/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 08:26:54 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/11 13:43:13 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;
	
	public:
		HumanB(std::string name);
		~HumanB();

		Weapon	getWeapon();
		void	setWeapon(Weapon& weapon);
		bool	isUnarmed();
		void	attack();
};

#endif