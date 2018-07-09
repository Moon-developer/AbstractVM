/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:58:51 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/09 10:00:33 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HPP
# define PARSE_HPP


# include <limits.h>
# include <cfloat>
# include <cmath>
# include <iostream>
# include <vector>
# include <sstream>
# include <regex>
# include "Error.hpp"

std::vector<std::string>	splitspace(std::string input);

int		remove_comment(std::string & input);
void	validate(std::string & input, std::string cmds[]);
void	CheckOUFlow(std::string func, std::string num);

#endif
