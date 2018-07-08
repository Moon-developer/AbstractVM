/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10/31/41 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/08 14:17:19 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FACTORY_HPP
# define	FACTORY_HPP

#include "Operand.hpp"

class Factory {
	public:
		Factory( void ) {};
		Factory & operator=(Factory const & src) {
			if (this != &src) {
				*this = src;
			}
			return (*this);
		}
		~Factory( void ) {};
		IOperand const * createInt8(std::string const & value) const {
			return (new Operand<int8_t>(value, int8));
		}
		IOperand const * createInt16(std::string const & value) const {
			return (new Operand<int16_t>(value, int16));
		}
		IOperand const * createInt32(std::string const & value) const {
			return (new Operand<int32_t>(value, int32));
		}
		IOperand const * createFloat(std::string const & value) const {
			return (new Operand<float>(value, FLOAT));
		}
		IOperand const * createDouble(std::string const & value) const {
			return (new Operand<double>(value, DOUBLE));
		}
		IOperand const * createOperand(eOperandType type, std::string const & value) {
			switch (type) {
			case int8:
				return (this->createInt8(value));
			case int16:
				return (this->createInt16(value));
			case int32:
				return (this->createInt32(value));
			case FLOAT:
				return (this->createFloat(value));
			case DOUBLE:
				return (this->createDouble(value));
			}
		}
};

#endif
