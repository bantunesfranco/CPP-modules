/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 18:11:50 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/15 18:31:34 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int	main()
{
	Zombie zombie = Zombie("Bob");
	zombie.announce();
	randomChump("Jens");
	return (0);
}