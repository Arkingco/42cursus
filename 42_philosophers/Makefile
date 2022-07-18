# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 15:58:45 by kipark            #+#    #+#              #
#    Updated: 2022/07/18 16:12:18 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc
CC_FLAG = -Wextra -Wall -Werror
RM		= rm
RM_FLAG	= -rf
TEST =  -fsanitize=address -g3

SRCS		= 	philo.c
# 				pipex.c				\
# 				error.c				\
# 				parse.c				\
# 				child.c				\
# 				system_call_utils.c	

VPATH		=	$(ls -l)

OBJ_DIR = ./obj
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAG) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_FILE)
	$(CC) $(CC_FLAG) -o $@ $^

debug :
	make -C $(LIBFT_DIR)
	$(CC) $(CC_FLAG) -g -o $(NAME) $(SRCS) $(LIBFT_LIB)

clean :
	$(RM) $(RM_FLAG) $(OBJ_DIR)

fclean :
	make clean
	$(RM) $(RM_FLAG) $^ $(NAME)
	
re :
	make fclean
	make

.Phony : all clean fclean re