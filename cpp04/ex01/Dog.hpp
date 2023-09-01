/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:22 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 17:07:05 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class	Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog& dog);
		
		Dog& operator=(const Dog& dog);
		
		void	makeSound() const;
		void	setIdea(size_t i, std::string idea);
		void	getIdeas(void) const;

};

#endif
