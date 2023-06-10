/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 18:11:50 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/10 19:11:44 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int	main()
{
	Zombie* zombie = newZombie("Bob");
	zombie->announce();
	randomChump("Jens");
	delete zombie;
	return (0);
}