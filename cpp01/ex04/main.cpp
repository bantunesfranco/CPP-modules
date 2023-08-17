/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 17:06:25 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/17 11:18:59 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "replaceStr.hpp"
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		return (1);
	}

	std::ifstream	inputFile(argv[1]);
	std::string		string = argv[1];
	std::ofstream	outputFile(string.append(".replace").c_str());
	std::string		fileContent;
	std::string		line;

	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open infile" << std::endl;
		return (1);
	}
	
	while (std::getline(inputFile, line, static_cast<char>(std::cout.eof())))
		fileContent += line;
	
	replaceStr(fileContent, argv[2], argv[3]);
	inputFile.close();

	if (!outputFile.is_open())
	{
		std::cerr << "Failed to open outfile" << std::endl;
		return (1);
	}
	
	outputFile << fileContent;
	outputFile.close();
	return (0);
}
