/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:34 by kipark            #+#    #+#             */
/*   Updated: 2022/04/06 20:48:28 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// greedy algorithm 사용
// 옆에 있어야하는 노드의 값을 구하기
void algorithm_run(t_stack *a, t_stack *b)
{
	stack_all_pb(a, b);
	check_stack_size(b);
	int stack_b_cost[501];
	
	
}

int check_stack_size(t_stack *stack)
{
	t_stack *head;
	int size;

	size = 0;
	head = stack;
	if(stack->next == head)
		return (1);
	while(stack->next != head)
	{
		0
		stack = stack->next;
	}
	return (size);
}

void stack_all_pb(t_stack *a, t_stack *b)
{
	t_stack *head_a;

	head_a = a;
	if(a->next == head_a)
		push_swap_operations_p(&a, &b, PB);
	while(a->next != head_a)
	{
		push_swap_operations_p(&a, &b, PB);
		a = a->next;
	}
}