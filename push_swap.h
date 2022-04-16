/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:52 by kipark            #+#    #+#             */
/*   Updated: 2022/04/16 19:28:04 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define DEAFAULT_STACK_NODE_VALUE 424242424242
#define COST_ARRAY_SIZE 501
#define STACK_A 1
#define STACK_B 0

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	struct s_stack *previous;
	struct s_stack *next;
	long int	node_value; 
} t_stack;

typedef struct s_cost {
	int ra;
	int rb;
	int rra;
	int rrb;
	int rr;
	int rrr;
	int cost_value;
	int target_a;
	int target_b;
} t_cost;

typedef struct s_execute_cost {
	int ra;
	int rb;
	int rra;
	int rrb;
} t_excute_cost;

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
void push_swap_free(void **pointer);


void set_new_cost(t_cost *new_cost);
void check_stack_cost(t_cost *cost, t_stack *a, t_stack *b);
void check_stack_cost_b(t_cost *cost, t_stack *b);
int get_stack_length(t_stack *stack);

#endif