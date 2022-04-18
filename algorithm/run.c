/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:34 by kipark            #+#    #+#             */
/*   Updated: 2022/04/18 19:42:36 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void excute_cost(t_cost *cost, t_stack **a, t_stack **b)
{
	int count;

	count = 0;
	while(count++ < cost->rr)
		r_ra(a);
	count = 0;
	while(count++ < cost->ra)
		r_rb(a);
	count = 0;
	while(count++ < cost->rb)
		r_rr(a, b);
	count = 0;
	while(count++ < cost->rrr)
		rr_rra(a);
	count = 0;
	while(count++ < cost->rra)
		rr_rrb(a);
	count = 0;
	while(count++ < cost->rrb)
		rr_rrr(a, b);
	p_pa(a, b);
}

void cost_optimization(t_cost *cost)
{
	if(cost->ra > 0)
	{
		if(cost->rb > 0)
		{
			while(cost->ra != 0 && cost->rb != 0)
			{
				cost->ra -= cost->ra - 1;
				cost->rb -= cost->rb - 1;
				cost->rr = cost->rr + 1;
			}
		}
	}
	else if(cost -> rra > 0)
	{
		if(cost->rrb > 0)
		{
			while(cost->rra != 0 && cost->rrb != 0)
			{
				cost->rra -= cost->rra - 1;
				cost->rrb -= cost->rrb - 1;
				cost->rrr = cost->rrr + 1;
			}
		}
	}
}

void stack_push_all_pb(t_stack **a, t_stack **b)
{
	int stack_length;

	stack_length = get_stack_length(*a, *a);
	if(stack_length <= 3)
		return ;
	while(1)
	{
		p_pb(a, b);
		stack_length--;
		if(stack_length <= 3)
			return ;
	}
}

void show_stack(t_stack *a, t_stack *b, char *flag)
{
	int i;
	t_stack *a_head = a;
	t_stack *b_head = b;
	
	printf("------------%s--------------\n", flag);
	i = 1;
	while(1)
	{
		if(a == NULL)
			return ;
		printf("--a : [%d] %ld\n", i, a->node_value);
		if(a->next == a_head)
			break;
		a = a->next;
		++i;
	}
	printf("-------b------\n");
	i = 1;
	while(1)
	{
		if(b == NULL)
			return ;
		printf("--b : [%d] %ld\n", i, b->node_value);
		if(b->next == b_head)
			break;
		b = b->next;
		++i;
	}
	printf("\n\n");
}

void algorithm_run(t_stack *a, t_stack *b)
{
	t_cost cost;
	int stack_a_sotring_size;

	stack_a_sotring_size = get_stack_length(a, a);
	stack_push_all_pb(&a, &b);
	while(get_stack_length(a, a) != stack_a_sotring_size)
	{
		printf("%d  %d \n", get_stack_length(a, a), get_stack_length(b, b));
		show_stack(a, b, "[in while]");
		set_new_cost(&cost);
		check_stack_cost(&cost, a, b);
		cost_optimization(&cost);
		excute_cost(&cost, &a, &b);
	}
	show_stack(a, b, "[in while]");
}