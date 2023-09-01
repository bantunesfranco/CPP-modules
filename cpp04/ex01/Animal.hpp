/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:13 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 16:57:22 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class	Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& animal);
		
		Animal& operator=(const Animal& animal);
		
		virtual void		makeSound() const;
		std::string	getType(void) const;
		void		setType(std::string type);
};

#endif
