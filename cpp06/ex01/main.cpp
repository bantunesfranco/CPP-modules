/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 17:52:42 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/11 09:26:19 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data*		data = new Data();
	
	std::cout << "\n" << *data << std::endl;

	uintptr_t	serialized = Serializer::serialize(data);
	Data*		deserialized = Serializer::deserialize(serialized);

	std::cout << *deserialized << std::endl;

	std::cout << "data:			" << data << std::endl;
	std::cout << "deserialized:	" << deserialized << std::endl;

	std::cout << std::endl;

	delete	data;
}
