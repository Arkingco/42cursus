/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_p.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:49:30 by kipark            #+#    #+#             */
/*   Updated: 2022/04/04 16:25:04 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static void push_swap_operations_p_delete_node(t_stack **head)
{
	t_stack *temp_head;
	
	if((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		head = NULL;
		return ;
	}
	else if((*head)->next)
	{
		temp_head = *head;
		*head = (*head)->next;
		(*head)->previous = temp_head->previous;
		free(temp_head);
		temp_head = NULL;
	}
}

static void push_swap_operations_p_pa(t_stack **a, t_stack **b)
{
	if(*b == NULL)
		return;
	stack_operations_add(a, (*b)->node_value);
	push_swap_operations_p_delete_node(b);
}

static void push_swap_operations_p_pb(t_stack **a, t_stack **b)
{
	if(*a == NULL)
		return;
	stack_operations_add(b, (*a)->node_value);
	push_swap_operations_p_delete_node(a);
}



void push_swap_operations_p(t_stack **a, t_stack **b, enum e_operations opers)
{
	if(opers == PA)
		push_swap_operations_p_pa(a, b);
	if(opers == PB)
		push_swap_operations_p_pb(a, b);
	return ;
}
