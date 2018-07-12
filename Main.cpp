/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:28:43 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/12 10:54:58 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

// return true if exit cmd found for file
//bool	find_exit(std::string file)
//{
//	std::string		line;
//	std::ifstream	input;
//	bool			exit = false;
//
//	try
//	{
//		input.open(file);
//		while (std::getline(input, line))
//			if (remove_comment(line) == 0)
//				exit = true;
//		input.close();
//		if (exit == true)
//			return (true);
//		else
//			throw Error::SyntaxError();
//	}
//	catch (std::exception & e) 
//	{
//		std::cout << e.what() << std::endl;
//		return (false);
//	}
//}

// loop thru each line in the file 
void	parse_file(std::string file)
{
	std::ifstream	input;
//	std::string		line;
//	bool			exit = false;

	input.open(file);
//	if (find_exit(file) == false)
//	{
//		std::cout << "No exit command found in "+file << std::endl;
//		return ;
//	}
//	while (std::getline( input, line ) && exit != true)
//	{
//		std::string	cmds[4];
//		try
//		{
//			validate(line, cmds);
//			if (cmds[3] == "end") {
//				exit = true;
//			}
//			else if (cmds[3] == "reg_cmd")
//				std::cout << "run push command here" << std::endl;
//				//run_reg_cmds(cmds[0], stack);
//			else if (cmds[3] == "push/assert")
//			{
//				if (cmds[0] == "push") {
//					std::cout << "run push command here" << std::endl;
//					//push(cmds, stack);
//				}
//				else if (cmds[0] == "assert") {
//					std::cout << "run assert command here" << std::endl;
//					assert(cmds, stack); // checks if the instance at the top of 
//												the stack is of the same type and value
//				}
//			}
//			else if (cmds[3] == "end")
//				std::cout << line << std::endl;
//		}
//		catch (std::exception & e) 
//		{
//			std::cout << e.what() << std::endl;
//		}
//	}
	input.close();
}

// check if given files is a valid .avm file
void	read_files(char **files, int total) {
	for (int index = 1; index < total; index++) {
		std::string	file = files[index];
		std::size_t found = file.find(".avm");
		if (found!=std::string::npos)
			parse_file(files[index]);
		else
			std::cout << "invalid file : " << files[index] << std::endl;
	}
}

// loop for all possible inputs
void	loop(void)  {
	bool					exit = false;
	std::string				input;
	std::string				test;
	std::vector<IOperand const *>	stack;
	int						line = 0;

	while (!exit) {
		std::getline (std::cin, input);
		try {
			std::string		cmds[4];
			line++;
			validate(line, input, cmds);
			if (cmds[3] == "end") {
				for (int i = stack.size() - 1; i >= 0; i--)
					delete stack[i];
				exit = true;
			}
			if (cmds[3] == "reg_cmd")
				run_reg_cmds(cmds, stack, line);
			if (cmds[3] == "push/assert") {
				if (cmds[0] == "push")
					push(line, cmds, stack, input);
				else if (cmds[0] == "assert")
					assert(line, cmds, stack, input);
			}
			if (cmds[3] == "end")
				std::cout << input << std::endl;
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
}

// start vm and look for input file or wait for input
int		main(int ac, char **av) {
	if (ac > 1)
		read_files(av, ac);
	else
		loop();
	return (0);
}
