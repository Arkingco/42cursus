# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 15:58:45 by kipark            #+#    #+#              #
#    Updated: 2022/07/29 05:23:27 by baggiseon        ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc
CC_FLAG = -Wextra -Wall -Werror
RM		= rm
RM_FLAG	= -rf
TEST =  -fsanitize=address -g3

SRCS		= 	philo.c			\
				philo_init.c	\
				philo_utils.c	\
				philo_die.c		\
				parser.c		\
				parser_atoi.c	\
				parser_error.c	\
				error.c			\
				utils.c			\
				thread.c		\

DEBUG_SRCS		= 	philo.c			\
				parse/parser.c		\
				parse/parser_atoi.c	\
				parse/parser_error.c	\
				error.c			\
				utils.c			\
				thread.c		\		
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
	$(RM) $(RM_FLAG) $^ $(NAME)
	
re :
	make fclean
	make
	./$(NAME) 190 300 100 100

debug :
	$(CC) $(CC_FLAG) -g -o $(NAME) $(DEBUG_SRCS)

.Phony : all clean fclean re