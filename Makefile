# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:26:51 by kipark            #+#    #+#              #
#    Updated: 2022/02/07 14:12:21 by kipark           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC 			= gcc
C_FLAG   	= -Wall -Wextra -Werror

RM			= rm
RM_PLAG		= -f

AR			= ar
AR_FLAG		= crs

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

OBJ_FILE_P1_P2	=	$(SRC:.c=.o)		

OBJ_FILE_BONUS  =	$(SRC_PART_BONUS:.c=.o) 

ifdef WITH_BONUS
    OBJ_FILE = $(OBJ_FILE_P1_P2) $(OBJ_FILE_BONUS)
else
    OBJ_FILE = $(OBJ_FILE_P1_P2)
endif

 .PHONY : all clean fclean re bonus

all : $(NAME)

%.o : %.c
	$(CC) $(C_FLAG) -c $< -o $@

clean	:
	$(RM) $(RM_PLAG) $(OBJ_FILE_P1_P2) $(OBJ_FILE_BONUS)

fclean	: clean
	$(RM) $(RM_PLAG) $(NAME)

$(NAME) : $(OBJ_FILE)
	$(AR) $(AR_FLAG) $@ $^

bonus	:
	make WITH_BONUS=1 all

re	: fclean all