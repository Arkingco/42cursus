# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 15:13:41 by kipark            #+#    #+#              #
#    Updated: 2022/05/02 17:13:22 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

CFLAGS 	= -Wall -Wextra -Werror
CC 		= gcc

RM 		= rm
RM_FLAGS = -rf

MLXLIB = libmlx.dylib
MLX_DIR = ./mlx

SRC =       so_long.c						\
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

VPATH		= $(shell ls -R)

all : $(NAME)

$(NAME) : $(SRC)
	@make -sC $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLXLIB) .
	$(CC) $(CFLAGS) -o $@ $^ $(MLXLIB)

fclean : clean mclean

clean :
	$(RM) $(RM_FLAGS) $(NAME)

mclean :
	$(RM) $(RM_FLAGS) $(MLXLIB)
	@make -sC $(MLX_DIR) clean

re : fclean
	make

 .PHONY : all clean fclean re
 