/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 17:32:49 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/11 10:53:28 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

typedef	unsigned long	uintptr_t;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();

		Serializer&			operator=(const Serializer &src);
	
	public:
		static Data*		deserialize(uintptr_t raw);
		static uintptr_t	serialize(Data* ptr);
};

#endif
