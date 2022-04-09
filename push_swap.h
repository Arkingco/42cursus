/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:52 by kipark            #+#    #+#             */
/*   Updated: 2022/04/09 15:23:21 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define DEAFAULT_STACK_NODE_VALUE 424242424242
#define COST_ARRAY_SIZE 501

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	struct s_stack *previous;
	struct s_stack *next;
	long int	node_value; 
} t_stack;

typedef struct s_cost {
	int top_down[COST_ARRAY_SIZE];
	int bottom_up[COST_ARRAY_SIZE];
	t_stack *pointer;
} t_cost;

enum e_operations {
	SA = 0, SB, SS,
	PA,  PB,
	RA,  RB,  RR,
	RRA, RRB, RRR	
};

t_stack *new_node_set(long int node_value);
int stack_operations_add(t_stack **head_node, long int node_value);

void	push_swap_operations_s(t_stack *a, t_stack *b, enum e_operations opers);
void	push_swap_operations_p(t_stack **a, t_stack **b, enum e_operations opers);
void	push_swap_operations_r(t_stack **a, t_stack **b, enum e_operations opers);
void	push_swap_operations_rr(t_stack **a, t_stack **b, enum e_operations opers);

char		**push_swap_parser_split(char const *s, char c);
long int	*parser(char *s);
long int	parse_atoi(const char *str);
int	parse_row_length(char **input_argv);
int paser_check_str_error(char *str);
int paser_error(char **need_parsed);

void print_error();
void error_exit();

void push_swap_memset(void *arr, int arr_length);

void check_stack_cost_a(t_cost *cost, t_stack *a, t_stack *b);
void check_stack_cost_b(t_cost *cost, t_stack *b);
int get_stack_length(t_stack *stack);

#endif