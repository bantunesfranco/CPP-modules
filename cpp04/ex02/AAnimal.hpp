/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:13 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/13 20:16:49 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class	AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(std::string);
		virtual ~AAnimal();
		AAnimal(const AAnimal& animal);
		
		AAnimal& operator=(const AAnimal& animal);
		
		virtual void		makeSound() const = 0;
		std::string	getType(void) const;
		void		setType(std::string type);
};

#endif