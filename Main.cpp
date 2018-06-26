/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:28:43 by mafernan          #+#    #+#             */
/*   Updated: 2018/06/25 14:47:52 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"
#include "Stack.hpp"

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

// loop for all possible inputs
void	loop(void) {
	bool					exit = false;
	std::string				input;
	std::string				test;
	Stack <IOperand>			stk;
	
	while (!exit) {
		std::getline (std::cin, input);
		if (input == ";;") {
			exit = true;
		}
		IOperand	IO(input);
		stk.push(IO);
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
