# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:26:51 by kipark            #+#    #+#              #
#    Updated: 2022/02/28 16:56:03 by kipark           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC 			= gcc
CFLAGS   	= -Wall -Wextra -Werror

RM			= rm
RM_FLAGS	= -f

AR			= ar
AR_FLAGS	= crs

format_src = 	format/ft_printf_format_c.c 		\
				format/ft_printf_format_d.c 		\
				format/ft_printf_format_i.c 		\
				format/ft_printf_format_p.c 		\
				format/ft_printf_format_s.c 		\
				format/ft_printf_format_u.c 		\
				format/ft_printf_format_x_x.c 		\
				format/ft_printf_format_x.c 		\

util =	util/ft_printf_str_util.c \

ft_printf = ft_printf.c

SRC				=	$(format_src) 		\
					$(util)				\
					$(ft_printf)		\

OBJ_FILE	=	$(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I inc

 .PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ_FILE)
	$(AR) $(AR_FLAGS) $@ $^

clean	:
	$(RM) $(RM_FLAGS) $(OBJ_FILE)

fclean	: clean
	$(RM) $(RM_FLAGS) $(NAME)

re	: fclean all