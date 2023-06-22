/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 12:29:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/21 19:42:00 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap	bob("bob");

	bob.attack("target");
	bob.setHitPts(20);
	bob.takeDamage(5);
	bob.beRepaired(5);
	 
	ScavTrap	joe(bob);

	joe.setName("joe");

	joe.setEnergy(100);
	joe.setHitPts(110);
	bob.setAtkDmg(10);
	bob.setEnergy(100);
	for (int i = 0; i < 10; i++)
	{
		bob.attack("joe");
		joe.takeDamage(bob.getAtkDmg());
	}
	joe.attack("bob");
	bob.takeDamage(joe.getAtkDmg());
	bob.beRepaired(1);
	bob.beRepaired(100);

	bob.guardGate();

	return (0);
}