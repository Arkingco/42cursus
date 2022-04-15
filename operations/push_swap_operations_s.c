/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_s.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:00:07 by kipark            #+#    #+#             */
/*   Updated: 2022/04/15 20:33:58 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static void push_swap_operations_s_swap(t_stack *ab)
{
	int temp;
	
	if(ab->next == NULL)
		return ;
	temp = ab->node_value;
	ab->node_value = ab->next->node_value;
	ab->next->node_value = temp;
}

static void push_swap_operations_s_sa(t_stack *a)
{
	return (push_swap_operations_s_swap(a));
}

static void push_swap_operations_s_sb(t_stack *b)
{
	return (push_swap_operations_s_swap(b));
}

static void push_swap_operations_s_ss(t_stack *a, t_stack *b)
{
	push_swap_operations_s_swap(a);
	push_swap_operations_s_swap(b);
	return ;
}

void push_swap_operations_s(t_stack *a, t_stack *b, enum e_operations opers)
{
	if(opers == SA)
		push_swap_operations_s_sa(a);
	if(opers == SB)
		push_swap_operations_s_sb(b);
	if(opers == SS)
		push_swap_operations_s_ss(a, b);
	return ;
}