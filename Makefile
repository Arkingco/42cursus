# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 15:13:41 by kipark            #+#    #+#              #
#    Updated: 2022/05/01 15:21:15 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CC = gcc
OBJ = main.c

OBJ_TEST =  so_long.c                       \
            gnl/get_next_line.c             \
            gnl/get_next_line_utils.c       \
            parser/error_utils.c            \
            parser/error.c                  \
            parser/parse_utils.c            \
            parser/parse.c                  \
            so_long.h                       \
            event/key.c                     \
            event/map.c                     \
            event/key_event.c               \
            error.c                         

all : $(NAME)

$(NAME) : $(OBJ_TEST)
	$(CC) $(CFLAGS) -g $^ libmlx.dylib

# clean	:
# 	$(RM) $(RM_FLAGS) $(NAME)

# $.o: $.c
#   $(CC) -Wall -Werror -Wextra -Imlx -c $< -o $@

# all : 
#   $(CC) -Wall -Werror -Wextra $(OBJ_TEST)

# $(NAME): $(OBJ)
#   $(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
