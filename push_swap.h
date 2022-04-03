/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:52 by kipark            #+#    #+#             */
/*   Updated: 2022/04/03 17:27:13 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define DEAFAULT_STACK_NODE_VALUE 424242424242

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	struct s_stack *previous;
	struct s_stack *next;
	long int	node_value; 
} t_stack;

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
long int	*push_swap_parse(char *s);
long int	parse_atoi(const char *str);
int	need_parse_length(char **input_argv);


#endif