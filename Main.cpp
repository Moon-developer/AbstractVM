/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:28:43 by mafernan          #+#    #+#             */
/*   Updated: 2018/06/26 15:36:55 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"
#include "Stack.hpp"
#include <vector>
#include <sstream>

template < typename P >
void print( std::stack<P>& stk ) {
	struct cheat : std::stack<P> {
		using std::stack<P>::c; 
	};
	auto& seq = static_cast< cheat& >(stk).c;

	for( auto& v : seq )
		std::cout << v.getvalue() << std::endl;
	std::cout << '\n' ;
}

// retunr a vector of words to loop thru
std::vector<std::string>	splitspace(std::string input) {
	std::string					buff;	
	std::stringstream			ss(input);
	std::vector<std::string>	words;

	while (ss >> buff) {
		words.push_back(buff);
	}
	return (words);
}

// return number of words in a string
int		wordcount(std::string input) {
	std::string			buff;	
	std::stringstream	ss(input);
	int					count;

	std::vector<std::string>	words;
	while (ss >> buff) {
		words.push_back(buff);
	}
	count = words.size();
	return (count);
}

// check if input options are true
bool	validate(std::string input) {
	std::vector<std::string>	cmdlist;	
	std::string 				types[5] = {"int8", "int16", "int32", "float", "double"};
	std::string					cmds[9] = {"add", "mul", "pop", "dump", "sub", 
											"div", "mod", "print", "exit"};

	std::transform(input.begin(), input.end(), input.begin(), ::tolower);
	if (wordcount(input) > 2) {
		std::cout << "Too many arguments or invalid argument type:\n\t" << input << std::endl;
		return (false);
	}
	for (int i = 0; i < 9; i++)
		if (input == cmds[i])
			return (true);
	if (wordcount(input) == 2) {
		cmdlist = splitspace(input);
		if (cmdlist[0] == "push" || cmdlist[0] == "assert")
			return (true);
		for (int i = 0; i < 5; i++) {
			for (int n = 0; n < (int)types[i].size(); n++)
				if (cmdlist[1][n] != types[i][n]) {
					std::cout << "invalid type :\n - " << cmdlist[1] << std::endl;
					return (false);
				}
		}
	}
	std::cout << "Given input was invalid :\n - " << input << std::endl;
	return (false);
}

// loop for all possible inputs
void	loop(void) {
	bool					exit = false;
	std::string				input;
	std::string				test;
	Stack <IOperand>		stk;
	
	while (!exit) {
		std::getline (std::cin, input);
		if (input == ";;") {
			exit = true;
		}
		if (validate(input) == true) {
			IOperand	IO(input);
			stk.push(IO);
		}
	}
}

// start vm and look for input file or wait for input
int		main(int ac, char **av) {
	(void)av;
	Error error;
	if (ac > 1) {
		std::cout << "Add file parser here" << std::endl;
	}
	else
		loop();
	return (0);
}
