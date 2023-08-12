/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:13 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/12 11:45:58 by bfranco       ########   odam.nl         */
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
		Animal(std::string);
		virtual ~Animal();
		Animal(const Animal& animal);
		
		Animal& operator=(const Animal& animal);
		
		virtual void		makeSound() const;
		std::string	getType(void) const;
		void		setType(std::string type);
};

#endif