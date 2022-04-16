/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:34 by kipark            #+#    #+#             */
/*   Updated: 2022/04/16 18:58:29 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// greedy algorithm 사용
// 옆에 있어야하는 노드의 값을 구하기
// 노드의 cost를 만들었다 
void algorithm_run(t_stack *a, t_stack *b)
{
	t_cost cost_a;
	t_cost cost_b;
	
	stack_push_all_pb(a, b);
	check_stack_cost(&cost_a, a, b);
	 
	
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