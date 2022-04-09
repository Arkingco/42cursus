/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:34 by kipark            #+#    #+#             */
/*   Updated: 2022/04/09 15:52:56 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// greedy algorithm 사용
// 옆에 있어야하는 노드의 값을 구하기

void algorithm_run(t_stack *a, t_stack *b)
{
	t_cost cost_a;
	t_cost cost_b;
	
	stack_push_all_pb(a, b);
	check_stack_size(b);
	check_stack_cost_b(&cost_b, b);
	check_stack_cost_a(&cost_a, a, b);
	
}

void stack_all_pb(t_stack *a, t_stack *b)
{
	t_stack *head_a;

	if(get_stack_length(a) <= 2)
		return ;
	head_a = a;
	if(a->next == head_a)
		push_swap_operations_p(&a, &b, PB);
	while(a->next != head_a)
	{
		push_swap_operations_p(&a, &b, PB);
		a = a->next;
		if(get_stack_length(a) <= 2)
			break;
	}
}