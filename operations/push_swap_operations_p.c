/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_p.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:49:30 by kipark            #+#    #+#             */
/*   Updated: 2022/04/17 15:21:14 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void push_swap_operations_p_delete_node(t_stack **head)
{
	t_stack *temp_head;
	
	if((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
		head = NULL;
		return ;
	}
	else if((*head)->next != NULL)
	{
		temp_head = *head;
		*head = (*head)->next;
		(*head)->previous = temp_head->previous;
		free(temp_head);
		temp_head = NULL;
	}
}

void push_swap_operations_p_pa(t_stack **a, t_stack **b, t_stack_info *info_a)
{
	if(*b == NULL)
		return;
	stack_operations_add(a, (*b)->node_value, info_a);
	push_swap_operations_p_delete_node(b);
}

void push_swap_operations_p_pb(t_stack **a, t_stack **b, t_stack_info *info_b)
{
	if(*a == NULL)
		return;
	stack_operations_add(b, (*a)->node_value, info_b);
	push_swap_operations_p_delete_node(a);
}
