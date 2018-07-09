/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:56:46 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/09 14:42:47 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Commands.hpp"

void	run_reg_cmds(std::string cmd, std::vector<IOperand const *> & stack)
{
	if (cmd == "add")
	{
		if (stack.size() < 2)
			throw Error::StackSizeError();
		else
		{
			IOperand const * pop1 = stack[stack.size() - 1];
			IOperand const * pop2 = stack[stack.size() - 2];
			IOperand const * newop;
			newop = *pop1 + *pop2;
			delete pop1;
			delete pop2;
			stack.pop_back();
			stack.pop_back();
			stack.push_back(newop);
		}
	}
	else if (cmd == "dump")
	{
		if (stack.size() < 1)
			throw Error::StackSizeError();
		else
			for (int i = stack.size() - 1; i >= 0; i--)
				std::cout << stack[i]->toString() << std::endl;
	}
/*	else if (cmd == "mod")
	{

	}
	else if (cmd == "sub")
	{

	}
	else if (cmd == "div")
	{

	}
	else if (cmd == "mul")
	{

	}
	else if (cmd == "pop")
	{

	}
	else if (cmd == "print")
	{

	}*/
}

void	push(std::string cmds[4], std::vector<IOperand const *> & stack)
{
	CheckOUFlow(cmds[1], cmds[2]);
	Factory	f;
	if (cmds[1] == "int8")
	{
		IOperand const * op = f.createOperand(eOperandType::int8, cmds[2]);
		stack.emplace_back(op);
	}
	else if (cmds[1] == "int16")
	{
		IOperand const * op = f.createOperand(eOperandType::int16, cmds[2]);
		stack.emplace_back(op);
	}
	else if (cmds[1] == "int32")
	{
		IOperand const * op = f.createOperand(eOperandType::int32, cmds[2]);
		stack.emplace_back(op);
	}
	else if (cmds[1] == "float")
	{
		IOperand const * op = f.createOperand(eOperandType::FLOAT, cmds[2]);
		stack.emplace_back(op);
	}
	else if (cmds[1] == "double")
	{
		IOperand const * op = f.createOperand(eOperandType::DOUBLE, cmds[2]);
		stack.emplace_back(op);
	}
}
