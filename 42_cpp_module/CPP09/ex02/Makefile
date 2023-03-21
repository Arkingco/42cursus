# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 12:57:37 by kipark            #+#    #+#              #
#    Updated: 2023/03/22 07:56:50 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 						= 	PmergeMe

CXX							=	c++
CXXFLAGS					=	-Wall -Wextra -Werror -std=c++98
SRCS						=	main.cpp				\
								PmergeMe.cpp

OBJS						=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME)		: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re
