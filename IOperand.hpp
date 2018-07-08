/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10/38/23 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/08 09:40:45 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		IOPERAND_HPP
# define	IOPERAND_HPP

# include <iostream>
# include <string>

enum eOperandType {
	int8,
	int16,
	int32,
	FLOAT,
	DOUBLE,
};

class IOperand {
	public:
		virtual int getPrecision( void ) const = 0; //Precision of the type of the instance
		virtual eOperandType getType( void ) const = 0; //Type of the instance

	//	virtual IOperand const * operator+( IOperand const & rhs ) const = 0; //Sum
	//	virtual IOperand const * operator-( IOperand const & rhs ) const = 0; //Difference
	//	virtual IOperand const * operator*( IOperand const & rhs ) const = 0; //Product
	//	virtual IOperand const * operator/( IOperand const & rhs ) const = 0; //Quotient
	//	virtual IOperand const * operator%( IOperand const & rhs ) const = 0; //Modulo

		virtual std::string const & toString( void ) const = 0; //Str representation of the instance

		virtual ~IOperand( void ) {};
};

template<typename T>
class Operand : public IOperand {
	public:
		std::string			_val;
		eOperandType		_type;

		Operand(std::string val, eOperandType type) : _val(val), _type(type) {}; // sets val and type
		Operand( Operand const & src ) { *this = src; } // copy constructor
		virtual ~Operand( void ) {}; // deconstructor
		virtual eOperandType getType( void ) const { // get Type function
			return (_type);
		}
		virtual int getPrecision( void ) const { //Precision of the type of the instance
			switch (_type) {
				case int8:
					return (0);
				case int16:
					return (1);
				case int32:
					return (2);
				case FLOAT:
					return (3);
				case DOUBLE:
					return (4);
			}
		}
		virtual std::string const & toString( void ) const { // return a string instance of value
			return (_val);
		}
		Operand & operator=(Operand const & src) { // equal operator
			if (this != &src) {
				*this = src;
			}
			return (*this);
		}
};

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
			case 0:
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


