/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:22 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/13 20:19:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class	Dog : public AAnimal
{
	private:
		Brain*	_brain = NULL;

	public:
		Dog();
		~Dog();
		Dog(const Dog& dog);
		
		Dog& operator=(const Dog& dog);
		
		void	makeSound() const;
		void	setIdea(std::string);
};

#endif