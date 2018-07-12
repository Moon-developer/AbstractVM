/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:05:15 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/12 10:42:09 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

// Nested error handling classes
class Error {
	public:
		class SyntaxError : public std::exception {
			public:
				std::string		e_msg;
				SyntaxError(const std::string& line, const std::string& input) {
					e_msg = std::string("Syntax ERROR on line ["+line+"] "+input);
				}
				virtual const char* what() const throw() {
						return e_msg.c_str();
				}
		};
		class OverflowError : public std::exception {
			public:
				std::string		e_msg;
				OverflowError(const std::string& line, const std::string& input) {
					e_msg = std::string("Overflow ERROR on line ["+line+"] "+input);
				}
				virtual const char* what() const throw() {
						return e_msg.c_str();
				}
		};
		class UnderflowError : public std::exception {
			public:
				std::string		e_msg;
				UnderflowError(const std::string& line, const std::string& input) {
					e_msg = std::string("Underflow ERROR on line ["+line+"] "+input);
				}
				virtual const char* what() const throw() {
						return e_msg.c_str();
				}
		};
		class InstructionError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "Unknown Instruction given.";
				}
		};
		class EmptyError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "Stack size ERROR: Attempted command on empty stack.";
				}
		};
		class ZeroError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "Operator ERROR: Can't mod/div by zero!";
				}
		};
		class ExitError : public std::exception {
			public:
				virtual const char* what() const throw() {
						return "File Format ERROR: No exit command found!";
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
						return "Stack size less than two to use command!";
				}
		};
		class NotInt8 : public std::exception {
			public:
				std::string		e_msg;
				 NotInt8(const std::string& line, const std::string& input) {
				 	e_msg = std::string("ASCII Convertion ERROR on line ["+line+"] "+input);
				 }
				virtual const char* what() const throw() {
						return e_msg.c_str();
				}
		};
		virtual const char* what() const throw() { 
			return "Unknown Error!"; 
		}
};
