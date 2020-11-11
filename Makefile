# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 13:18:04 by epalomak          #+#    #+#              #
#    Updated: 2020/11/11 11:23:55 by epalomak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = project

SRC = ./src/*

OBJ = *.o

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

all: $(NAME)

checker:
	make -C libft
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(OBJ) $(LIBFT) -o checker

push_swap:
	@make -C libft
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(OBJ) $(LIBFT) -o push_swap

$(NAME): checker push_swap

clean:
	@make -C libft clean
	@/bin/rm -f *.o

fclean: clean
	@make -C libft fclean
	@/bin/rm -f checker push_swap

re: fclean all
