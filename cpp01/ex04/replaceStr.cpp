/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   replaceStr.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 17:06:23 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/11 17:42:14 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "replaceStr.hpp"

void	replaceStr(std::string& fileContent, const std::string s1, const std::string s2)
{
	size_t	startPos = fileContent.find(s1, 0);

	while (startPos != std::string::npos)
	{
		fileContent.erase(startPos, s1.length());
		fileContent.insert(startPos, s2);
		startPos += s2.length();
		startPos = fileContent.find(s1, startPos);
	}	
}