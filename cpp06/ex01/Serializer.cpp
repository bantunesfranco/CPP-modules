/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 17:32:46 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 17:59:06 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

// Serializer::Serializer()
// {
// 	return ;
// }

// Serializer::~Serializer()
// {
// 	return ;
// }

// Serializer::Serializer(const Serializer &src)
// {
// 	(void)src;
// 	return ;
// }

// Serializer&	Serializer::operator=(const Serializer &src)
// {
// 	(void)src;
// 	return (*this);
// }

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
