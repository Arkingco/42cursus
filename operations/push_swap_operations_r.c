/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_r.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:18:19 by kipark            #+#    #+#             */
/*   Updated: 2022/03/31 21:52:57 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void push_swap_operations_r(t_stack **a, t_stack **b, enum e_operations opers)
{
	if(opers == RA)
		push_swap_operations_r_ra(a, b);
	if(opers == RB)
		push_swap_operations_r_rb(a, b);
	if(opers == RR)
		push_swap_operations_r_rr(a, b);
	return ;
}

static void push_swap_operations_r_ra(t_stack **a, t_stack **b)
{
	if(*a == NULL)
		return ;
	if((*a)->next == NULL)
		return ;
	return (push_swap_operations_r_works(a));
}

static void push_swap_operations_r_rb(t_stack **a, t_stack **b)
{
	if(*b == NULL)
		return ;
	if((*b)->next == NULL)
		return ;
	return (push_swap_operations_r_works(b));
}

static void push_swap_operations_r_rr(t_stack **a, t_stack **b)
{
	push_swap_operations_r_ra(a, b);
	push_swap_operations_r_rb(a, b);
	return ;
}

static void push_swap_operations_r_works(t_stack **head)
{
	*head = (*head)->next;
	return ;
}
