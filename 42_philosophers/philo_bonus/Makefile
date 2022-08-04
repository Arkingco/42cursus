# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 15:58:45 by kipark            #+#    #+#              #
#    Updated: 2022/08/04 21:07:02 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus

CC		= cc
CC_FLAG = -Wextra -Wall -Werror -fsanitize=thread -g3
RM		= rm
RM_FLAG	= -rf
TEST =  -fsanitize=address -g3

SRCS		= 	philo_bonus.c			\
				philo_init_bonus.c	\
				philo_utils_bonus.c	\
				philo_die_bonus.c		\
				parser_bonus.c		\
				parser_atoi_bonus.c	\
				parser_error_bonus.c	\
				error_bonus.c			\
				utils_bonus.c			\
				thread_bonus.c		\

VPATH		= $(shell ls -R)

OBJ_DIR = ./obj
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o : %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAG) -g -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_FILE)
	$(CC) $(CC_FLAG) -o $@ $^

clean :
	$(RM) $(RM_FLAG) $(OBJ_DIR)

fclean :
	make clean
	$(RM) $(RM_FLAG) $(NAME)
	
re :
	make fclean
	make
	./philo_bonus 5 620 200 200

debug :
	$(CC) $(CC_FLAG) -g -o $(NAME) $(DEBUG_SRCS)

.Phony : all clean fclean re