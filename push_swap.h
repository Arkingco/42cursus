/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:52 by kipark            #+#    #+#             */
/*   Updated: 2022/04/22 16:19:16 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define DEAFAULT_STACK_NODE_VALUE 424242424242
# define COST_ARRAY_SIZE 501
# define STACK_A 1
# define STACK_B 0

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	struct s_stack	*previous;
	struct s_stack	*next;
	long int		node_value;
	int				stack_length;
}	t_stack;

typedef struct s_cost {
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	cost_value;
	int	target_a;
	int	target_b;
}	t_cost;

t_stack	*new_node_set(long int node_value);
int		stack_operations_add(t_stack **head, long int node_value);

void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	delete_node(t_stack **head);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rrb(t_stack **b);
void	rra(t_stack **a);
void	rrr(t_stack **a, t_stack **b);

char	**push_swap_parser_split(char const *s, char c);
long	int	*parser(char *s);
long	int	parse_atoi(const char *str);
int		parse_row_length(char **input_argv);
int		paser_check_str_error(char *str);
int		paser_error(char **need_parsed);

void	print_error(int exit_flag);
void	error_exit(int exit_flag);

void	push_swap_stack_free(t_stack *stack, int stack_length);
void	push_swap_memset(void *arr, int arr_length);
void	push_swap_free(void **pointer);
void	push_swap_double_arr_free(char **pointer);

void	set_arr(t_stack *a, int *arr, int b_node);
int		find_target_in_arr(int *arr, int array_size, int b_node);
void	excute_cost(t_cost *cost, t_stack **a, t_stack **b);
void	cost_optimization(t_cost *cost);

void	find_min_cost(t_cost *cost, t_cost *new_cost);
void	set_new_cost(t_cost *new_cost);
int		check_arr_is_sort(t_stack *a, t_stack *head);

void	algorithm_run(t_stack *a, t_stack *b);
void	sort_arr_stack(int *arr, int arr_length);
void	stack_sort_third(t_stack **a);
void	stack_sort_second(t_stack **a);
void	sort_arr(int *arr, int left, int right);

void	show_stack(t_stack *a, t_stack *b, char *flag);
void	check_stack_cost(t_cost *cost, t_stack *a, t_stack *b);
void	heck_stack_cost_b(t_cost *cost, t_stack *b);
int		get_stack_length(t_stack *stack, t_stack *head_stack);

#endif