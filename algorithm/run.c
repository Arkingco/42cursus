/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:34 by kipark            #+#    #+#             */
/*   Updated: 2022/04/13 15:37:52 by kipark           ###   ########.fr       */
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
	check_stack_size(b);
	check_stack_cost_b(&cost_b, b);
	check_stack_cost_a(&cost_a, a, b);
	push_stack_b_to_a(&cost_a, &cost_b);
	

	// 마지막은 스택 a 정렬하는 알고리즘
	// 이거는 코스트 b 를 사용해서 a 의 코스트를 구하고 탑다운 바텀업 값을 구하면 될 것 같음
}

void push_stack_b_to_a(t_stack *a, t_stack *b)
{
		
}

void stack_all_pb(t_stack *a, t_stack *b)
{
	t_stack *head_a;
	int stack_length;

	stack_length = get_stack_length(a);
	if(stack_length <= 2)
		return ;
	head_a = a;
	while(a->next != head_a)
	{
		push_swap_operations_p(&a, &b, PB);
		a = a->next;
		stack_length--;
		if(stack_length <= 2)
			return ;
	}
}