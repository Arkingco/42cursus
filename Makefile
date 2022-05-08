# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 09:04:34 by kipark            #+#    #+#              #
#    Updated: 2022/05/08 18:44:49 by baggiseon        ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc
CC_FLAG = -Wextra -Wall -Werror
RM		= rm
RM_FLAG	= -rf

SRC			= 	pipex.c			\
				error.c
VPATH		=	$(ls -l)

OBJ_FILE	= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILE)
	$(CC) $(CC_FLAG) -o $@ $^

clean :
	$(RM) $(RM_FLAG) $(OBJ_FILE)

fclean : clean
	$(RM) $(RM_FLAG) $^ $(NAME)

re :
	make fclean
	make

.Phony : all clean fclean re
