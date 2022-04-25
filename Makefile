# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 15:01:44 by kipark            #+#    #+#              #
#    Updated: 2022/04/23 19:39:29 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC 			= gcc
CFLAGS   	= -Wall -Wextra -Werror

RM			= rm
RM_FLAGS	= -rf

push_swap_dir = push_swap.c 					\
				operations/operations_stack.c	\
				operations/operations_p.c 		\
				operations/operations_r.c 		\
				operations/operations_rr.c 		\
				operations/operations_s.c 		\
				parser/parser_atoi.c			\
				parser/parser_error.c			\
				parser/parser_split.c			\
				parser/parser_util.c			\
				parser/parser.c					\
				algorithm/cost.c				\
				algorithm/cost_utils.c			\
				algorithm/solve.c				\
				algorithm/solve_utils.c			\
				algorithm/sort.c				\
				error.c							\
				push_swap_util.c

all : $(NAME)

$(NAME) : $(push_swap_dir)
	$(CC) $(CFLAGS) -o $@ $^

clean	:
	$(RM) $(RM_FLAGS) $(NAME)

fclean	: clean

re	: fclean all

 .PHONY : all clean fclean re