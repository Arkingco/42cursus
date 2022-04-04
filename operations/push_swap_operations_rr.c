/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_rr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:16:41 by kipark            #+#    #+#             */
/*   Updated: 2022/04/04 16:31:12 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static void push_swap_operations_rr_works(t_stack **head)
{
	*head = (*head)->previous;
	return ;
}

static void push_swap_operations_rr_rra(t_stack **a)
{
	return (push_swap_operations_rr_works(a));
}

static void push_swap_operations_rr_rrb(t_stack **b)
{
	return (push_swap_operations_rr_works(b));
}

static void push_swap_operations_rr_rrr(t_stack **a, t_stack **b)
{
	push_swap_operations_rr_works(a);
	push_swap_operations_rr_works(b);
	return ;
}

void push_swap_operations_rr(t_stack **a, t_stack **b, enum e_operations opers)
{
	if(opers == RRA)
		push_swap_operations_rr_rra(a);
	if(opers == RRB)
		push_swap_operations_rr_rrb(b);
	if(opers == RRR)
		push_swap_operations_rr_rrr(a, b);
	return ;
}