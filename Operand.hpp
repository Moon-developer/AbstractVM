/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 13/38/57 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/11 08:24:46 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		OPERAND_HPP
# define	OPERAND_HPP

# include "IOperand.hpp"
# include <cmath>

template<typename T>
class Operand : public IOperand {
	public:
		std::string			_val;
		eOperandType		_type;

		Operand(std::string val, eOperandType type); 
		Operand( Operand const & src );
		virtual ~Operand( void ); 
		virtual eOperandType getType( void ) const;
		virtual int getPrecision( void ) const;
		virtual std::string const & toString( void ) const;
		IOperand const & operator=( IOperand const & rhs); 
		virtual IOperand const * operator+( IOperand const & rhs ) const; 
		virtual IOperand const * operator-( IOperand const & rhs ) const; 
		virtual IOperand const * operator*( IOperand const & rhs ) const; 
		virtual IOperand const * operator/( IOperand const & rhs ) const; 
		virtual IOperand const * operator%( IOperand const & rhs ) const; 
};

#include "Operand.cpp"

#endif
