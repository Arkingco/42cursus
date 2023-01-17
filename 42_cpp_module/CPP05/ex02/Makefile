# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 11:11:09 by kipark            #+#    #+#              #
#    Updated: 2023/01/14 15:31:44 by kipark           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME 						= 	ex02

CXX							=	c++
CXXFLAGS					=	-Wall -Wextra -Werror -std=c++98
SRCS						=	main.cpp					\
								Bureaucrat.cpp				\
								AForm.cpp					\
								ShrubberyCreationForm.cpp	\
								RobotomyRequestForm.cpp		\
								PresidentialPardonForm.cpp

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
