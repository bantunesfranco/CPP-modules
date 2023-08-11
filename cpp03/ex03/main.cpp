/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 12:29:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 09:29:30 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	DiamondTrap	bob("bob");
	DiamondTrap	joe("joe");
	DiamondTrap	test(joe);

	std::cout << "\nBob: " << "hp = " << bob.getHitPts() << " atk = " \
	<< bob.getAtkDmg() << " energy = " << bob.getEnergy() << std::endl;
	bob.attack("target");
	std::cout << "" << std::endl;

	test.setRealName("test1234");

	bob.setAtkDmg(2);
	bob.setEnergy(2);
	
	for (int i = 0; i < 4; i++)
	{
		bob.attack("joe");
		joe.takeDamage(bob.getAtkDmg());
	}
	std::cout << "" << std::endl;
	
	bob.takeDamage(20);
	bob.beRepaired(5);
	std::cout << "" << std::endl;

	for (int i = 0; i < 7; i++)
		joe.beRepaired(2);
	std::cout << "" << std::endl;

	joe.setHitPts(2);
	joe.setEnergy(0);
	joe.beRepaired(2);
	std::cout << "" << std::endl;

	bob.highFivesGuys();
	joe.guardGate();
	std::cout << "" << std::endl;

	bob.whoAmI();
	joe.whoAmI();
	test.whoAmI();

	joe = bob;
	joe.whoAmI();
	std::cout << "" << std::endl;

	return (0);
}