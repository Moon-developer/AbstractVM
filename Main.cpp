/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:28:43 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/02 15:50:47 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"
#include <string>
#include <iostream>
#include <fstream>

void	parse_file(std::string file)
{
	std::ifstream	input;
	std::string		line;
	bool			exit = false;

	input.open(file);
	while (std::getline( input, line ) && exit != true)
	{
		std::string*	cmds = new std::string[4];
		try
		{
			validate(line, cmds);
			if (cmds[3] == "end") {
				exit = true;
			}
			else if (cmds[3] == "ignore")
				std::cout << "comment : " << line << std::endl;
			else if (cmds[3] == "reg_cmd")
				std::cout << "reg cmd : " + line << std::endl;
			else if (cmds[3] == "push/assert")
			{
				CheckOUFlow(cmds[1], cmds[2]);
				std::cout << "adv cmd : " + line << std::endl;
			}
			else if (cmds[3] == "end")
				std::cout << "reached end with : " + line << std::endl;
		}
		catch (std::exception & e) 
		{
			std::cout << e.what() << std::endl;
		}
		delete [] cmds;
	}
	input.close();
}

void	read_files(char **files, int total)
{
	std::regex	ext("\\w*.(avm)");

	for (int index = 1; index < total; index++)
	{
		if (std::regex_match(files[index], ext) == true)
		{
			std::cout << "reading : " << files[index] << std::endl;
			parse_file(files[index]);
		}
		else
			std::cout << "invalid file : " << files[index] << std::endl;
	}
}

// loop for all possible inputs
void	loop(void) 
{
	bool					exit = false;
	std::string				input;
	std::string				test;

	while (!exit) 
	{
		std::getline (std::cin, input);
		try
		{
			std::string*	cmds = new std::string[4];
			validate(input, cmds);
			if (cmds[3] == "end") {
				exit = true;
			}
			if (cmds[3] == "ignore")
				std::cout << "comment : " << input << std::endl;
			if (cmds[3] == "reg_cmd")
				std::cout << "reg cmd : " + input << std::endl;
			if (cmds[3] == "push/assert")
			{
				CheckOUFlow(cmds[1], cmds[2]);
				std::cout << "adv cmd : " + input << std::endl;
			}
			if (cmds[3] == "end")
				std::cout << "reached end with : " + input << std::endl;
			delete [] cmds;
		}
		catch (std::exception & e) 
		{
			std::cout << e.what() << std::endl;
		}
	}
}

// start vm and look for input file or wait for input
int		main(int ac, char **av)
{
	if (ac > 1)
		read_files(av, ac);
	else
		loop();
	return (0);
}
