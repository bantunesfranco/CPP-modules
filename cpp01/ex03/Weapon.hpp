/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 08:27:06 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/13 19:41:24 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();

		void				setType(std::string type);
		std::string const&	getType(void) const;
};

#endif
