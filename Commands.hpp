/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:11:39 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/09 10:20:47 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
# define COMMANDS_HPP

# include <vector>
# include <iostream>
# include "Operand.hpp"
# include "Parse.hpp"

void	push(std::string cmds[], std::vector<IOperand const *> & stack);
void	run_reg_cmds(std::string cmd, std::vector<IOperand const *> & stack);

#endif
