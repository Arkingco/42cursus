# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:26:51 by kipark            #+#    #+#              #
#    Updated: 2022/01/24 18:33:29 by kipark           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CC_plag = -Wextra -Werror -Wall

src = ft_printf.c

format_src = 	format/ft_printf_format_c.c 		\
				format/ft_printf_format_d.c 		\
				format/ft_printf_format_i.c 		\
				format/ft_printf_format_p.c 		\
				format/ft_printf_format_s.c 		\
				format/ft_printf_format_u.c 		\
				format/ft_printf_format_x_x.c 		\
				format/ft_printf_format_x.c 		\

util =	util/ft_printf_str_util.c \
		
all :
	$(CC) $(SRC) $(format_src) $(util) $(src)