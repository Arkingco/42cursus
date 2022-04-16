/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:34 by kipark            #+#    #+#             */
/*   Updated: 2022/04/16 20:14:35 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// greedy algorithm 사용
// 옆에 있어야하는 노드의 값을 구하기
// 노드의 cost를 만들었다 
void algorithm_run(t_stack *a, t_stack *b)
{
	t_cost cost;
	int stack_a_sotring_size;

	stack_a_sotring_size = get_stack_length(a);
	stack_push_all_pb(a, b);
	while(get_stack_length(a) != stack_a_sotring_size)
	{
		set_new_cost(&cost);
		check_stack_cost(&cost, a, b);
		cost_optimization(&cost);
		excute_cost(&cost, a, b);
	}
}

void excute_cost(t_cost *cost, t_stack *a, t_stack *b)
{
	int count;

	count = 0;
	while(count++ < cost->rr)
		push_swap_operations_rr(a, b, RR);
	count = 0;
	while(count++ < cost->ra)
		push_swap_operations_r(a, b, RA);
	count = 0;
	while(count++ < cost->rb)
		push_swap_operations_r(a, b, RB);
	count = 0;
	while(count++ < cost->rrr)
		push_swap_operations_rr(a, b, RRR);
	count = 0;
	while(count++ < cost->rra)
		push_swap_operations_rr(a, b, RRA);
	count = 0;
	while(count++ < cost->rrb)
		push_swap_operations_rr(a, b, RRB);
	push_swap_operations_p(a, b, PA);
}

void cost_optimization(t_cost *cost)
{
	if(cost->ra > 0)
		if(cost->rb > 0)
		{
			while(cost->ra != 0 && cost->rb != 0)
			{
				cost->ra -= cost->ra - 1;
				cost->rb -= cost->rb - 1;
				cost->rr = cost->rr + 1;
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
		push_swap_operations_p(&a, &b, PB);
		a = a->next;
		stack_length--;
		if(stack_length <= 3)
			return ;
	}
}