/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:13 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 14:24:56 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal(std::string);
		~Animal();
		Animal(const Animal& animal);
		
		Animal& operator=(const Animal& animal);
		
		void		makeSound() const;
		std::string	getType(void) const;
		void		setType(std::string type);
}

#endif