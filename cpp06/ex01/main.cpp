/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 17:52:42 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 18:11:21 by bfranco       ########   odam.nl         */
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
	delete	deserialized;
}
