/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:04:48 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/12 16:26:15 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"
#include "Operand.hpp"

Factory::Factory( void ) {};

Factory & Factory::operator=(Factory const & src) {
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

Factory::~Factory( void ) {};

IOperand const * Factory::createInt8(std::string const & value) const {
	return (new Operand<int8_t>(value, int8));
}

IOperand const * Factory::createInt16(std::string const & value) const {
	return (new Operand<int16_t>(value, int16));
}

IOperand const * Factory::createInt32(std::string const & value) const {
	return (new Operand<int32_t>(value, int32));
}
IOperand const * Factory::createFloat(std::string const & value) const {
	return (new Operand<float>(value, FLOAT));
}
IOperand const * Factory::createDouble(std::string const & value) const {
	return (new Operand<double>(value, DOUBLE));
}
IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const {
	pt2Function PointerFuncArr [] {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble
	};
	pt2Function	func = PointerFuncArr[type];
	return ((this->*func)(value));
}
