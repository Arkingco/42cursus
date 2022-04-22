/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:33:51 by kipark            #+#    #+#             */
/*   Updated: 2022/04/22 13:32:13 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_arr(t_stack *a, int *arr, int b_node)
{
	t_stack	*a_head;
	int		i;

	a_head = a;
	if (a_head == NULL)
		return ;
	i = 0;
	while (1)
	{
		arr[i] = a->node_value;
		++i;
		if (a->next == a_head)
			break ;
		a = a->next;
	}
	arr[i] = b_node;
}

int	find_target_in_arr(int *arr, int array_size, int b_node)
{
	int	i;

	i = 0;
	while (i < array_size)
	{
		if (arr[i] == b_node)
		{
			return (arr[(i + 1) % array_size]);
		}
		++i;
	}
	return (-1);
}

void	set_new_cost(t_cost *new_cost)
{
	new_cost->ra = 0;
	new_cost->rra = 0;
	new_cost->rb = 0;
	new_cost->rrb = 0;
	new_cost->rr = 0;
	new_cost->rrr = 0;
	new_cost->target_a = 0;
	new_cost->target_b = 0;
	new_cost->cost_value = 0;
}

void	find_min_cost(t_cost *cost, t_cost *new_cost)
{
	if (cost->cost_value > new_cost->cost_value)
	{
		cost->ra = new_cost->ra;
		cost->rra = new_cost->rra;
		cost->rb = new_cost->rb;
		cost->rrb = new_cost->rrb;
		cost->rr = new_cost->rr;
		cost->rrr = new_cost->rrr;
		cost->target_a = new_cost->target_a;
		cost->target_b = new_cost->target_b;
		cost->cost_value = new_cost->cost_value;
	}
}
