/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:22:40 by kipark            #+#    #+#             */
/*   Updated: 2022/04/12 20:51:25 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void check_stack_cost_b(t_cost *cost, t_stack *b)
{
	int top_depth;
	int bottom_depth;
	t_stack *head;
	
	top_depth = 1;
	
	head = b;
	if (b->next == head)
		cost->top_down[top_depth] = top_depth;
	while(b->next != head)
	{
		cost->top_down[top_depth] = top_depth;
		top_depth++;
		b = b->next;
	}
	bottom_depth = top_depth;
	while(bottom_depth != 0)
	{
		cost->bottom_up[bottom_depth] = bottom_depth + 1;
		bottom_depth--;
	}
}

int get_stack_length(t_stack *stack)
{
	int length;
	t_stack *head;

	if(head == NULL)
		return (0);
	length = 1;
	head = stack;
	while(stack->next != head)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

void check_stack_cost_a(t_cost *cost, t_stack *a, t_stack *b)
{
	int top_down_length;
	int stack_b_length;
	int stack_a_length;
	t_stack *a_head;

	a_head = a;
	top_down_length = 0;
	stack_a_length = get_stack_length(a);
	stack_b_length = get_stack_length(b);
	while(stack_b_length--)
	{
		while(1)
		{
			if(a->previous->node_value < b->node_value && a->next->node_value > b->node_value)
			{
				cost->top_down[b->node_value] = top_down_length;
				cost->bottom_up[b->node_value] = stack_a_length - top_down_length;
				break;
			}	
			a = a->next;
			top_down_length++;
		}
		b = b->next;
		a = a_head;
	}
}
