/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_rr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:16:41 by kipark            #+#    #+#             */
/*   Updated: 2022/03/31 22:03:54 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void push_swap_operations_rr(t_stack **a, t_stack **b, enum e_operations opers)
{
	if(opers == RRA)
		push_swap_operations_rr_rra(a, b);
	if(opers == RRB)
		push_swap_operations_rr_rrb(a, b);
	if(opers == RRR)
		push_swap_operations_rr_rrb(a, b);
	return ;
}

static void push_swap_operations_rr_rra(t_stack **a, t_stack **b)
{
	return (push_swap_operations_rr_works(a));
}

static void push_swap_operations_rr_rrb(t_stack **a, t_stack **b)
{
	return (push_swap_operations_rr_works(b));
}

static void push_swap_operations_rr_rrr(t_stack **a, t_stack **b)
{
	push_swap_operations_rr_works(a);
	push_swap_operations_rr_works(b);
	return ;
}

static void push_swap_operations_rr_works(t_stack **head)
{	
	*head = (*head)->previous;
	return ;
}

