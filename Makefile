#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 15:56:35 by nfruneau          #+#    #+#              #
#    Updated: 2018/06/22 15:17:20 by mafernan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

COM = clang++

FLAGS = -Wall -Werror -Wextra

NAME = avm

SRC = Main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COM) $(FLAGS) -o $(NAME) $(OBJ)
	@rm *.o

%.o: %.cpp
	$(COM) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
