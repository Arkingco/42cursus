/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:49:30 by kipark            #+#    #+#             */
/*   Updated: 2022/04/17 15:24:40 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	delete_node(t_stack **head)
{
	t_stack	*temp_head;

	if ((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
		head = NULL;
		return ;
	}
	else
	{
		temp_head = (*head);
		(*head)->next->previous = (*head)->previous;
		(*head)->previous->next = (*head)->next;
		(*head)->next->stack_length = (*head)->stack_length - 1;
		(*head) = (*head)->next;
		free(temp_head);
		temp_head = NULL;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	if (b == NULL || *b == NULL)
		return ;
	stack_operations_add(a, (*b)->node_value);
	delete_node(b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a == NULL || a == NULL)
		return ;
	stack_operations_add(b, (*a)->node_value);
	delete_node(a);
	write(1, "pb\n", 3);
}
