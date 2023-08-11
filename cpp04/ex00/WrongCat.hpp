/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 18:52:05 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 19:01:07 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		virtual ~WrongCat();
		WrongCat(const WrongCat& wrongcat);
		
		WrongCat& operator=(const WrongCat& wrongcat);
		
		void		makeSound() const;
};

#endif