/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:22:40 by kipark            #+#    #+#             */
/*   Updated: 2022/04/07 19:44:57 by kipark           ###   ########seoul.kr  */
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

void check_stack_cost_a(t_cost *cost, t_stack *a)
{

}
