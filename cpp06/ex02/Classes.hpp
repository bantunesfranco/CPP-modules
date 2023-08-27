/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Classes.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 18:40:21 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 18:44:10 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
