# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 09:04:34 by kipark            #+#    #+#              #
#    Updated: 2022/05/16 21:07:38 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc
CC_FLAG = -Wextra -Wall -Werror
RM		= rm
RM_FLAG	= -rf
LIBFT_DIR = libft
LIBFT_LIB = libft.a
SRC			= 	pipex.c				\
				error.c				\
				paser/parse.c		\
				system_call_utils.c
VPATH		=	$(ls -l)

OBJ_FILE	= $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CC_FLAG) -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@make -sC $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT_LIB) .
	$(CC) $(CC_FLAG) -g -o $@ $^ $(LIBFT_LIB)

debug :
	$(CC) $(CC_FLAG) -g -o $(NAME) $(SRC) $(LIBFT_LIB)


clean :
	$(RM) $(RM_FLAG) $(OBJ_FILE)

fclean : clean
	@make -sC $(LIBFT_DIR) fclean
	$(RM) $(RM_FLAG) $^ $(NAME)
	$(RM) $(RM_FLAG) $(LIBFT_LIB)
	$(RM) $(RM_FLAG) out*

re :
	make fclean
	make

.Phony : all clean fclean re
