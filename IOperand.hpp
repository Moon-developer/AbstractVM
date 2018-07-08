/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10/38/23 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/08 10:47:43 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		IOPERAND_HPP
# define	IOPERAND_HPP

# include <iostream>
# include <string>
# include "Factory.hpp"

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

		virtual IOperand const * operator+( IOperand const & rhs ) const = 0; //Sum
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
		virtual IOperand const * operator+( IOperand const & rhs ) const { //Sum
			long double		lhs_val = std::stold(this->_val);
			long double		rhs_val = std::stold(rhs.toString());
			long double		result = lhs_val + rhs_val;
			Factory			f;
			int		lhs_prec = this->getPrecision();
			int		rhs_prec = rhs.getPrecision();
			IOperand const * op = NULL;
			if (lhs_prec < rhs_prec)
				op = f.createOperand( rhs.getType() ,std::to_string(result));
			else
				op = f.createOperand( this->getType() ,std::to_string(result));
			return (op);
		}
};

#endif


