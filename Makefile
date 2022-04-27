# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 15:13:41 by kipark            #+#    #+#              #
#    Updated: 2022/04/27 16:51:42 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CC = gcc
OBJ = main.c

OBJ_TEST =  so_long.c                       \
            gnl/get_next_line_bonus.c       \
            gnl/get_next_line_utils_bonus.c \
            so_long.h                       
            

all : $(NAME)

$(NAME) : $(OBJ_TEST)
	$(CC) $(CFLAGS) $^

# clean	:
# 	$(RM) $(RM_FLAGS) $(NAME)

# $.o: $.c
#   $(CC) -Wall -Werror -Wextra -Imlx -c $< -o $@

# all : 
#   $(CC) -Wall -Werror -Wextra $(OBJ_TEST)

# $(NAME): $(OBJ)
#   $(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
