/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Parsing.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/27 10:45:23 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/27 19:39:27 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
#define PARSING_HPP

#include <string>

bool	isInt(std::string input);
bool	isFloat(std::string input);
bool	isDouble(std::string input);
bool	isChar(std::string input);
bool	isPseudoLiteral(std::string input);

void	printInt(std::string input);
void	printFloat(std::string input);
void	printDouble(std::string input);
void	printChar(std::string input);
void	printPseudoLiteral(std::string input);

#endif
