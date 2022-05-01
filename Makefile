# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 15:13:41 by kipark            #+#    #+#              #
#    Updated: 2022/05/01 20:34:48 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long
CFLAGS 	= -Wall -Wextra -Werror
CC 		= gcc
RM 		= rm
RM_FLAGS = -rf
SRC_TEST =  so_long.c						\
            get_next_line.c					\
            get_next_line_utils.c			\
            error_utils.c					\
            parse_error.c					\
            parse_utils.c					\
            key.c							\
            map.c							\
            key_event.c						\
            error.c							\
            parse.c

INCS		= so_long.h
OBJ_DIR		= objs

OBJ_TEST	= $(addprefix $(OBJ_DIR)/, $(SRC_TEST:.c=.o))

VPATH		= $(shell ls -R)

all : $(NAME)

$(NAME) : $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^ libmlx.dylib

$(OBJ_DIR)/%.o : %.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

fclean :
	$(RM) $(RM_FLAGS) $(NAME)
	$(MAKE) clean

clean :
	$(RM) $(RM_FLAGS) $(OBJ_DIR)

re : fclean
	$(MAKE)

 .PHONY : all clean fclean re
 