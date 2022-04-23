/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:23:58 by kipark            #+#    #+#             */
/*   Updated: 2022/04/20 21:32:49 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	excute_cost(t_cost *cost, t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (count++ < cost->rr)
		rr(a, b);
	count = 0;
	while (count++ < cost->ra)
		ra(a);
	count = 0;
	while (count++ < cost->rb)
		rb(b);
	count = 0;
	while (count++ < cost->rrr)
		rrr(a, b);
	count = 0;
	while (count++ < cost->rra)
		rra(a);
	count = 0;
	while (count++ < cost->rrb)
		rrb(b);
	pa(a, b);
}

void	cost_optimization(t_cost *cost)
{
	if (cost->ra > 0)
	{
		if (cost->rb > 0)
		{
			while (cost->ra != 0 && cost->rb != 0)
			{
				cost->ra = cost->ra - 1;
				cost->rb = cost->rb - 1;
				cost->rr = cost->rr + 1;
			}
		}
	}
	else if (cost -> rra > 0)
	{
		if (cost->rrb > 0)
		{
			while (cost->rra != 0 && cost->rrb != 0)
			{
				cost->rra = cost->rra - 1;
				cost->rrb = cost->rrb - 1;
				cost->rrr = cost->rrr + 1;
			}
		}
	}
}

int	check_arr_is_sort(t_stack *a, t_stack *head)
{
	long int	node_value;

	node_value = INT64_MIN;
	while (1)
	{
		if (a->node_value < node_value)
			return (0);
		node_value = a->node_value;
		if (a->next == head)
			break ;
		a = a->next;
	}
	return (1);
}
