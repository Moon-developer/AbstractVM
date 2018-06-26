/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:05:15 by mafernan          #+#    #+#             */
/*   Updated: 2018/06/22 15:16:28 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

// nested error handling classes
class Error {
	public:
		class SyntaxError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "incorrect syntax given. Please type correct inputs.";
				}
		};
		class OverflowError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "Overflow error occured.";
				}
		};
		class InstructionError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "Unknown Instruction given.";
				}
		};
		class UnderflowError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "Underflow error occured.";
				}
		};
		class EmptyError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "Instruction pop on an emtpy stack.";
				}
		};
		class ZeroError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "Tried to mod or divide by '0'.";
				}
		};
		class ExitError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "No exit instruction found.";
				}
		};
		class AssertError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "Assert instruction returned false.";
				}
		};
		class StackSizeError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "Stack containes less than two values.";
				}
		};
		virtual const char* what() const throw() { 
			return "Unknown Error!"; 
		}
};
