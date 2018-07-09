/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:56:46 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/09 09:27:53 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Commands.hpp"

void	push(std::string* & cmds, std::vector<IOperand const *> & stack)
{
	//CheckOUFlow(cmds[1], cmds[2]);
	Factory	f;
	if (cmds[1] == "int8")
	{
		IOperand const * op = f.createOperand(eOperandType::int8, cmds[2]);
		stack.push_back(op);
		delete op;
	}
	else if (cmds[1] == "int16")
	{
		IOperand const * op = f.createOperand(eOperandType::int16, cmds[2]);
		stack.push_back(op);
		delete op;
	}
	else if (cmds[1] == "int32")
	{
		IOperand const * op = f.createOperand(eOperandType::int32, cmds[2]);
		stack.push_back(op);
		delete op;
	}
	else if (cmds[1] == "float")
	{
		IOperand const * op = f.createOperand(eOperandType::FLOAT, cmds[2]);
		stack.push_back(op);
		delete op;
	}
	else if (cmds[1] == "double")
	{
		IOperand const * op = f.createOperand(eOperandType::DOUBLE, cmds[2]);
		stack.push_back(op);
		delete op;
	}
}
