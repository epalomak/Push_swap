# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 13:18:04 by epalomak          #+#    #+#              #
#    Updated: 2021/05/07 17:05:24 by epalomak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C = ./src/check_stack.c ./src/get_numbers.c ./src/handle_commands.c \
./src/checker_main.c 

SRC_PS = ./src/check_stack.c ./src/get_numbers.c ./src/handle_commands.c \
./src/push_swap.c ./src/sort.c ./src/sort_helper.c  ./src/sort_500.c

OBJ_C = check_stack.o get_numbers.o handle_commands.o \
checker_main.o

OBJ_PS = check_stack.o get_numbers.o handle_commands.o push_swap.o sort.o \
sort_helper.o sort_500.o

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

all: checker push_swap

checker:
	make -C libft
	@gcc $(FLAGS) -c $(SRC_C)
	@gcc $(OBJ_C) $(LIBFT) -o checker

push_swap:
	@make -C libft
	@gcc $(FLAGS) -c $(SRC_PS)
	@gcc $(OBJ_PS) $(LIBFT) -o push_swap

clean:
	@make -C libft clean
	@/bin/rm -f *.o

fclean: clean
	@make -C libft fclean
	@/bin/rm -f checker push_swap

re: fclean all
