/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:45:29 by kipark            #+#    #+#             */
/*   Updated: 2022/04/20 20:46:32 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

t_stack	*new_node_set(long int node_value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack) * 1);
	if (new_node == NULL)
		return ((t_stack *) NULL);
	new_node->previous = (t_stack *) NULL;
	new_node->next = (t_stack *) NULL;
	new_node->node_value = node_value;
	new_node->stack_length = 0;
	return (new_node);
}

int	stack_operations_add(t_stack **head, long int node_value)
{
	t_stack	*new_node;
	t_stack	*temp_head;

	new_node = NULL;
	temp_head = NULL;
	new_node = new_node_set(node_value);
	if (*head == NULL)
	{
		*head = new_node;
		(*head)->next = *head;
		(*head)->previous = *head;
		(*head)->stack_length = (*head)->stack_length + 1;
	}
	else
	{
		temp_head = *head;
		*head = new_node;
		(*head)->next = temp_head;
		(*head)->previous = temp_head->previous;
		(*head)->previous->next = *head;
		(*head)->stack_length = (*head)->next->stack_length + 1;
		temp_head->previous = *head;
	}
	return (1);
}
