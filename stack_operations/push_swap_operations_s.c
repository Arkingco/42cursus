/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_s.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:00:07 by kipark            #+#    #+#             */
/*   Updated: 2022/03/31 17:25:24 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void push_swap_operations_s(t_stack *a, t_stack *b, enum e_operations opers)
{
	if(opers == SA)
		push_swap_operations_s_sa(a, b);
	if(opers == SB)
		push_swap_operations_s_sb(a, b);
	if(opers == SS)
		push_swap_operations_s_ss(a, b);
	return ;
}

static void *push_swap_operations_s_swap(t_stack *ab)
{
	int temp;
	
	if(ab->next == NULL)
		return (ab);
	temp = ab->node_value;
	ab->node_value = ab->next->node_value;
	ab->next->node_value = temp;
	return (ab); 
}

static void push_swap_operations_s_sa(t_stack *a, t_stack *b)
{
	return push_swap_operations_s_swap(a);
}

static void push_swap_operations_s_sb(t_stack *a, t_stack *b)
{
	return push_swap_operations_s_swap(b);
}

static void push_swap_operations_s_ss(t_stack *a, t_stack *b)
{
	push_swap_operations_s_swap(a);
	push_swap_operations_s_swap(b);
	return ;
}
