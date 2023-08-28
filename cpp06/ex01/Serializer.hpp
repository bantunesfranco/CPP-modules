/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 17:32:49 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 17:53:50 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &src);
		virtual ~Serializer() = 0;

		virtual Serializer&			operator=(const Serializer &src) = 0;

		static Data*		deserialize(uintptr_t raw);
		static uintptr_t	serialize(Data* ptr);
};

#endif
