/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:18 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 17:09:23 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class	Cat : public AAnimal
{
	private:
		Brain* _brain;

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
