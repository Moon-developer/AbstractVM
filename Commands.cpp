/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:56:46 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/11 15:13:07 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Commands.hpp"

std::string	com_arr(std::string list[])
{
	std::string		result;
	int				size = list->size();

	if (size == 0)
		return ("");
	for (int i = 0; i < size - 2; i++)
		result += std::string(list[i]+" ");
	return (result);
}

void	run_reg_cmds(std::string cmds[4], std::vector<IOperand const *> & stack, int line)
{
	if (cmds[0] == "add")
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
	else if (cmds[0] == "mul")
	{
		if (stack.size() < 2)
			throw Error::StackSizeError();
		else
		{
			IOperand const * pop1 = stack[stack.size() - 1];
			IOperand const * pop2 = stack[stack.size() - 2];
			IOperand const * newop;
			newop = *pop1 * *pop2;
			delete pop1;
			delete pop2;
			stack.pop_back();
			stack.pop_back();
			stack.push_back(newop);
		}
	}
	else if (cmds[0] == "sub")
	{
		if (stack.size() < 2)
			throw Error::StackSizeError();
		else
		{
			IOperand const * pop1 = stack[stack.size() - 1];
			IOperand const * pop2 = stack[stack.size() - 2];
			IOperand const * newop;
			newop = *pop1 - *pop2;
			delete pop1;
			delete pop2;
			stack.pop_back();
			stack.pop_back();
			stack.push_back(newop);
		}
	}
	else if (cmds[0] == "div")
	{
		if (stack.size() < 2)
			throw Error::StackSizeError();
		else
		{
			IOperand const * pop1 = stack[stack.size() - 1];
			IOperand const * pop2 = stack[stack.size() - 2];
			IOperand const * newop;
			long double	temp = std::stold(pop2->toString());
			if (temp == 0)
				throw Error::ZeroError();
			newop = *pop1 / *pop2;
			delete pop1;
			delete pop2;
			stack.pop_back();
			stack.pop_back();
			stack.push_back(newop);
		}
	}
	else if (cmds[0] == "mod")
	{
		if (stack.size() < 2)
			throw Error::StackSizeError();
		else
		{
			IOperand const * pop1 = stack[stack.size() - 1];
			IOperand const * pop2 = stack[stack.size() - 2];
			IOperand const * newop;
			long double	temp = std::stold(pop2->toString());
			if (temp == 0)
				throw Error::ZeroError();
			newop = *pop1 % *pop2;
			delete pop1;
			delete pop2;
			stack.pop_back();
			stack.pop_back();
			stack.push_back(newop);
		}
	}
	else if (cmds[0] == "dump")
	{
		if (stack.size() < 1)
			throw Error::StackSizeError();
		else
			for (int i = stack.size() - 1; i >= 0; i--)
				std::cout << stack[i]->toString() << std::endl;
	}
	else if (cmds[0] == "pop")
	{
		if (stack.size() < 1)
			throw Error::EmptyError();
		else
		{
			IOperand const * pop1 = stack[stack.size() - 1];
			delete pop1;
			stack.pop_back();
		}
	}
	else if (cmds[0] == "print")
	{
		if (stack[stack.size() - 1]->getType() != 0)
			throw Error::NotInt8(std::to_string(line), com_arr(cmds));
		else
		{
			std::cout << "ascii : " << static_cast<char>(static_cast<int8_t>(std::stold(stack[stack.size() - 1]->toString()))) << std::endl;

		}
	}
}

void	push(int line, std::string cmds[4], std::vector<IOperand const *> & stack, std::string input)
{
	CheckOUFlow(line, cmds, input);
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
