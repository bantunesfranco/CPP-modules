/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 12:29:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/19 10:19:49 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap	bob("bob");
	bob.setName("joe");
	ScavTrap	joe = bob;
	bob.setName("bob");

	return (0);
}