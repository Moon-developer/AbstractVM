/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:28:43 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/08 15:34:44 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Main.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

// return true if exit cmd found for file
bool	find_exit(std::string file)
{
	std::string		line;
	std::ifstream	input;
	bool			exit = false;

	try
	{
		input.open(file);
		while (std::getline(input, line))
			if (remove_comment(line) == 0)
				exit = true;
		input.close();
		if (exit == true)
			return (true);
		else
			throw Error::SyntaxError();
	}
	catch (std::exception & e) 
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
}

// loop thru each line in the file 
void	parse_file(std::string file)
{
	std::ifstream	input;
	std::string		line;
	bool			exit = false;

	input.open(file);
	if (find_exit(file) == false)
	{
		std::cout << "No exit command found in "+file << std::endl;
		return ;
	}
	while (std::getline( input, line ) && exit != true)
	{
		std::string*	cmds = new std::string[4];
		try
		{
			validate(line, cmds);
			if (cmds[3] == "end") {
				exit = true;
			}
			else if (cmds[3] == "reg_cmd")
				std::cout << "run : " + line << std::endl;
			else if (cmds[3] == "push/assert")
			{
				CheckOUFlow(cmds[1], cmds[2]);
				std::cout << "run : " + line << std::endl;
			}
			else if (cmds[3] == "end")
				std::cout << line << std::endl;
		}
		catch (std::exception & e) 
		{
			std::cout << e.what() << std::endl;
		}
		delete [] cmds;
	}
	input.close();
}

// check if given files is a valid .avm file
void	read_files(char **files, int total)
{
	for (int index = 1; index < total; index++)
	{
		std::string	file = files[index];
		std::size_t found = file.find(".avm");
		if (found!=std::string::npos)
			parse_file(files[index]);
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
	std::vector<IOperand const *>	stack;

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
			if (cmds[3] == "reg_cmd")
				std::cout << "run : " + input << std::endl;
			if (cmds[3] == "push/assert")
			{
				CheckOUFlow(cmds[1], cmds[2]);
				Factory	f;
				IOperand const * op = f.createOperand(eOperandType::int8, cmds[2]);
				stack.emplace_back(op);
				delete op;
				std::cout << "stack size : " << stack.size() << std::endl;
				std::cout << "run : " + input << std::endl;
			}
			if (cmds[3] == "end")
				std::cout << input << std::endl;
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
