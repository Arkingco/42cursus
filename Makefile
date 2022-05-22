# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 09:04:34 by kipark            #+#    #+#              #
#    Updated: 2022/05/22 20:13:02 by baggiseon        ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc
CC_FLAG = -Wextra -Wall -Werror
RM		= rm
RM_FLAG	= -rf
LIBFT_DIR = libft
LIBFT_LIB = libft.a
TEST =  -fsanitize=address -g3

SRCS		= 	pipex.c				\
				error.c				\
				parse.c				\
				child.c				\
				system_call_utils.c	
VPATH		=	$(ls -l)

OBJ_DIR = ./obj
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAG) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_FILE)
	@make -sC $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT_LIB) .
	@$(CC) $(CC_FLAG) -g -o $@ $^ $(LIBFT_LIB)

debug :
	@make -sC $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT_LIB) .
	@$(CC) $(CC_FLAG) -g -o $(NAME) $(SRCS) $(LIBFT_LIB)

clean :
	@$(RM) $(RM_FLAG) $(OBJ_DIR)

fclean : clean
	@make -sC $(LIBFT_DIR) fclean
	$(RM) $(RM_FLAG) $^ $(NAME)
	$(RM) $(RM_FLAG) $(LIBFT_LIB)
	@$(RM) $(RM_FLAG) out*
	
re :
	make fclean
	make

.Phony : all clean fclean re