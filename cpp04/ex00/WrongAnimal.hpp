/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 18:52:01 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 16:57:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class	WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(std::string);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& wronganimal);
		
		WrongAnimal& operator=(const WrongAnimal& wronganimal);
		
		void		makeSound() const;
		std::string	getType(void) const;
		void		setType(std::string type);
};

#endif
