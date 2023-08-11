/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:22 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 18:19:27 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>

class	Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& dog);
		
		Dog& operator=(const Dog& dog);
		
		void		makeSound() const;
};

#endif