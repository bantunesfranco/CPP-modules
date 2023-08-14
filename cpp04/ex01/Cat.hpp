/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:18 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/14 15:09:48 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class	Cat : public Animal
{
	private:
		Brain* _brain = NULL;

	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& cat);
		
		Cat& operator=(const Cat& cat);
		
		void		makeSound() const;
		void	setIdea(size_t i, std::string idea);
		void	getIdeas(void) const;
};

#endif