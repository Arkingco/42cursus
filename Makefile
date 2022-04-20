cc = gcc
cc_flags = -Wall -Wextra -Werror

push_swap_dir = push_swap.c 					\
				operations/operations_stack.c	\
				operations/operations_p.c 		\
				operations/operations_r.c 		\
				operations/operations_rr.c 		\
				operations/operations_s.c 		\
				parser/parser_atoi.c			\
				parser/parser_error.c			\
				parser/parser_split.c			\
				parser/parser_util.c			\
				parser/parser.c					\
				algorithm/cost.c				\
				algorithm/cost_utils.c			\
				algorithm/solve.c				\
				algorithm/solve_utils.c			\
				algorithm/sort.c				\
				error.c							\
				push_swap_util.c

debug :
	$(cc) $(cc_flags) -g $(push_swap_dir)