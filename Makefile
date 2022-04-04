cc = gcc
cc_flags = -Wall -Wextra -Werror

push_swap_dir = main.c \
				operations/push_swap_operations_stack.c		\
				operations/push_swap_operations_p.c 		\
				operations/push_swap_operations_r.c 		\
				operations/push_swap_operations_rr.c 		\
				operations/push_swap_operations_s.c 		\
				parser/parser_atoi.c						\
				parser/parser_error.c						\
				parser/parser_split.c						\
				parser/parser_util.c						\
				parser/parser.c								\
				error.c

debug :
	$(cc) $(cc_flags) -g $(push_swap_dir)
