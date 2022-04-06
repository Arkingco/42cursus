/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push_swap_operations_stack.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:15:02 by kipark            #+#    #+#             */
/*   Updated: 2022/03/30 15:39:58 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

t_stack *new_node_set(long int node_value)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack) * 1);
	if(new_node == NULL)
		return ((t_stack *)NULL);
	new_node->previous = (t_stack *)NULL;
	new_node->next = (t_stack *)NULL;
	new_node->node_value = node_value;
	return (new_node);	
}

// head is already allocated using new_node_set
int stack_operations_add(t_stack **head, long int node_value)
{
	t_stack *new_node;
	t_stack *temp_head;

	new_node = NULL;
	temp_head = NULL;
	new_node = new_node_set(node_value);
	if(*head == NULL)
	{
		*head = new_node;
		(*head)->next = NULL;
		(*head)->previous = *head;
	}
	else
	{
		temp_head = *head;
		*head = new_node;
		(*head)->next = temp_head;
		(*head)->previous = temp_head->previous;
		(*head)->previous->next = *head;
		temp_head->previous = *head;
	}
	return (1);
}