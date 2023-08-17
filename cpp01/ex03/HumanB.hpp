/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 08:26:54 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/17 11:19:08 by bfranco       ########   odam.nl         */
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
		bool	isUnarmed();
	
	public:
		HumanB(std::string name);
		~HumanB();
		Weapon const&	getWeapon();
		void			setWeapon(Weapon& weapon);
		void			attack();
};

#endif
