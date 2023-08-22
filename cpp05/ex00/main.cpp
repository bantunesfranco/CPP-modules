/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 11:45:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/21 17:47:16 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat*	bob = new Bureaucrat("Bob", 50);
	Bureaucrat*	bob2 = new Bureaucrat("Bob2", 0);
	Bureaucrat*	bob3 = new Bureaucrat("Bob3", 151);

	delete bob;
	delete bob2;
	delete bob3;
}
