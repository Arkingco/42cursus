/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:52 by kipark            #+#    #+#             */
/*   Updated: 2022/04/19 22:14:51 by kipark           ###   ########.fr       */
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

t_stack *new_node_set(long int node_value);
int stack_operations_add(t_stack **head, long int node_value);

void p_pb(t_stack **a, t_stack **b);
void p_pa(t_stack **a, t_stack **b);
void p_delete_node(t_stack **head);

void s_sa(t_stack *a);
void s_sb(t_stack *b);
void s_ss(t_stack *a, t_stack *b);

void r_ra(t_stack **a);
void r_rb(t_stack **b);
void r_rr(t_stack **a, t_stack **b);

void rr_rrb(t_stack **b);
void rr_rra(t_stack **a);
void rr_rrr(t_stack **a, t_stack **b);

char		**push_swap_parser_split(char const *s, char c);
long int	*parser(char *s);
long int	parse_atoi(const char *str);
int	parse_row_length(char **input_argv);
int paser_check_str_error(char *str);
int paser_error(char **need_parsed);

void print_error();
void error_exit();

void push_swap_stack_free(t_stack **stack);
void push_swap_memset(void *arr, int arr_length);
void push_swap_free(void **pointer);
void push_swap_double_arr_free(char **pointer);

void algorithm_run(t_stack *a, t_stack *b);
void sort_arr(int *arr, int arr_length);

void show_stack(t_stack *a, t_stack *b, char *flag);
void set_new_cost(t_cost *new_cost);
void check_stack_cost(t_cost *cost, t_stack *a, t_stack *b);
void check_stack_cost_b(t_cost *cost, t_stack *b);
int	get_stack_length(t_stack *stack, t_stack *head_stack);

#endif