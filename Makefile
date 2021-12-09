# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 18:30:39 by kipark            #+#    #+#              #
#    Updated: 2021/12/08 22:17:24 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC 			= gcc
C_FLAG   	= -Wall -Wextra -Werror

RM			= rm
RM_PLAG		= -f

AR			= ar
AR_FLAG		= crs

SRC_PART_1	=		ft_isalpha.c	\
					ft_isdigit.c	\
					ft_isalnum.c	\
					ft_isascii.c	\
					ft_isprint.c	\
					ft_strlen.c		\
					ft_memset.c		\
					ft_bzero.c		\
					ft_memcpy.c		\
					ft_memmove.c	\
					ft_strlcpy.c	\
					ft_strlcat.c	\
					ft_toupper.c	\
					ft_tolower.c	\
					ft_strchr.c		\
					ft_strrchr.c	\
					ft_strncmp.c	\
					ft_memchr.c		\
					ft_memcmp.c		\
					ft_strnstr.c	\
					ft_atoi.c		\
					ft_calloc.c		\
					ft_strdup.c		\
			
SRC_PART_2	=       ft_substr.c		\
					ft_strjoin.c	\
					ft_strtrim.c	\
					ft_split.c		\
					ft_itoa.c		\
					ft_strmapi.c	\
					ft_striteri.c	\
					ft_putchar_fd.c	\
					ft_putstr_fd.c	\
					ft_putendl_fd.c	\
					ft_putnbr_fd.c	\

SRC_PART_BONUS =    ft_lstnew.c			\
					ft_lstadd_front.c	\
					ft_lstsize.c		\
					ft_lstlast.c		\
					ft_lstadd_back.c	\
					ft_lstdelone.c		\
					ft_lstclear.c		\
					ft_lstiter.c		\
					ft_lstmap.c			\

SRC				=	$(SRC_PART_1) 		\
					$(SRC_PART_2) 		\

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