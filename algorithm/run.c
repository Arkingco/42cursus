/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:34 by kipark            #+#    #+#             */
/*   Updated: 2022/04/17 15:44:56 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void excute_cost(t_cost *cost, t_stack *a, t_stack *b)
{
	int count;

	count = 0;
	while(count++ < cost->rr)
		r_rr(&a, &b);
	count = 0;
	while(count++ < cost->ra)
		r_rr(&a, &b);
	count = 0;
	while(count++ < cost->rb)
		r_rr(&a, &b);
	count = 0;
	while(count++ < cost->rrr)
		r_rrr(&a, &b);
	count = 0;
	while(count++ < cost->rra)
		r_rrr(&a, &b);
	count = 0;
	while(count++ < cost->rrb)
		r_rrr(&a, &b);
	p_pa(&a, &b);
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

void stack_push_all_pb(t_stack *a, t_stack *b)
{
	t_stack *head_a;
	int stack_length;

	stack_length = get_stack_length(a);
	if(stack_length <= 3)
		return ;
	head_a = a;
	while(a->next != head_a)
	{
		p_pb(&a, &b, PB);
		a = a->next;
		stack_length--;
		if(stack_length <= 3)
			return ;
	}
}

void show_stack(t_stack *a, t_stack *b, t_stack_info info_a, t_stack_info info_b)
{
	int i;
	t_stack *a_head = a;
	t_stack *b_head = b;

	i = 0;
	while(i++ < info_a.stack_length)
	{
		printf("a --- %ld \n", a->node_value);
		a = a->next;
	}
	i = 0;
	while(i++ < info_b.stack_length)
	{
		printf("b --- %ld\n", b->node_value);
		b = b->next;
	}

	printf("\n\n\n\n");
}

void algorithm_r_rrun(t_stack *a, t_stack *b)
{
	t_cost cost;
	t_stack_info
	int stack_a_sotring_size;

	stack_a_sotring_size = get_stack_length(a);
	stack_push_all_pb(a, b);
	while(get_stack_length(a) != stack_a_sotring_size)
	{
		show_stack(a, b);
		set_new_cost(&cost);
		check_stack_cost(&cost, a, b);
		cost_optimization(&cost);
		excute_cost(&cost, a, b);
	}
}