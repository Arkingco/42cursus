# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 11:11:09 by kipark            #+#    #+#              #
#    Updated: 2022/12/25 20:36:42 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 						= 	BackupProgram

CXX							=	c++
CPPFLAGS					=	-Wall -Wextra -Werror -std=c++98
SRCS						=	tests.cpp			\
								Account.cpp

OBJS						=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME)		: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re
