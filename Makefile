# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 09:04:34 by kipark            #+#    #+#              #
#    Updated: 2022/05/09 11:01:04 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc
CC_FLAG = -Wextra -Wall -Werror
RM		= rm
RM_FLAG	= -rf
LIBFT_DIR = /libft
LIBFT_LIB = libft.a
SRC			= 	pipex.c			\
				error.c
VPATH		=	$(ls -l)

OBJ_FILE	= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILE)
	@make -sC $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT_LIB) .
	$(CC) $(CC_FLAG) -o $@ $^

clean :
	$(RM) $(RM_FLAG) $(OBJ_FILE)

fclean : clean
	$(RM) $(RM_FLAG) $^ $(NAME)

re :
	make fclean
	make

.Phony : all clean fclean re
