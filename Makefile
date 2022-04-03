cc = gcc
cc_flags = -Wall -Wextra -Werror

push_swap_dir = main.c \
				stack_operations/push_swap_operations_stack.c		\
				stack_operations/push_swap_operations_p.c 		\
				stack_operations/push_swap_operations_r.c 		\
				stack_operations/push_swap_operations_rr.c 		\
				stack_operations/push_swap_operations_s.c 		\

debug :
	$(cc) $(cc_flags) -g $(push_swap_dir)
