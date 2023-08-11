/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:18 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 18:19:01 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>

class	Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& cat);
		
		Cat& operator=(const Cat& cat);
		
		void		makeSound() const;
};

#endif