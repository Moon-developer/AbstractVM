/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10/38/23 by mafernan          #+#    #+#             */
/*   Updated: 2018/06/25 14:23:56 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		IOPERAND_HPP
# define	IOPERAND_HPP

# include <iostream>
# include <string>

class IOperand {
	private:
		std::string _value;
	public:
		template<typename IN>
		IOperand( IN src ) {
			this->_value = src;
		}
		std::string	getvalue() {
			return this->_value;
		}
		~IOperand( void );


//		virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
//		virtual eOperandType getType( void ) const = 0; // Type of the instance
//		virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
//		virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
//		virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
//		virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
//		virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
//		virtual std::string const & toString( void ) const = 0; // Str representation of the instance

};

#endif


