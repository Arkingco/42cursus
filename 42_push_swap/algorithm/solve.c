/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:34 by kipark            #+#    #+#             */
/*   Updated: 2022/04/23 20:07:52 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static int	find_min_value_stack(t_stack *a, t_stack *head)
{
	long int	min_value;

	min_value = INT64_MAX;
	while (1)
	{
		if (min_value > a->node_value)
			min_value = a->node_value;
		if (a->next == head)
			break ;
		a = a->next;
	}
	return ((int)min_value);
}

static void	end_sort(t_stack **a, t_stack *a_a, t_stack *head, int stack_length)
{
	t_cost	cost;
	int		length;
	int		target_a;

	length = 0;
	target_a = find_min_value_stack(a_a, a_a);
	set_new_cost(&cost);
	while (1)
	{
		if (a_a->node_value == target_a)
		{
			cost.ra = length;
			cost.rra = stack_length - length;
			break ;
		}
		if (a_a->next == head)
			break ;
		a_a = a_a->next;
		length++;
	}
	if (cost.ra > cost.rra)
		cost.ra = -1;
	else
		cost.rra = -1;
	excute_cost(&cost, a, NULL);
}

static void	stack_push_all_pb(t_stack **a, t_stack **b)
{
	int	stack_length;
	int	pivot;

	stack_length = (*a)->stack_length;
	if (stack_length <= 3)
		return ;
	while (1)
	{
		pivot = (stack_length / 2);
		if ((*a)->node_value < pivot)
			ra(a);
		else
		{
			pb(a, b);
			stack_length--;
		}
		if (stack_length <= 3)
			return ;
	}
}

static void	soft_sort(t_stack **a)
{
	int	stack_length;

	stack_length = (*a)->stack_length;
	if (stack_length == 2)
		stack_sort_second(a);
	else if (stack_length == 3)
		stack_sort_third(a);
	else
		return ;
}

void	run_algorithm(t_stack *a, t_stack *b)
{
	t_cost	cost;
	int		stack_a_sotring_size;

	if (check_arr_is_sort(a, a))
		return ;
	stack_a_sotring_size = a->stack_length;
	stack_push_all_pb(&a, &b);
	soft_sort(&a);
	while (a->stack_length != stack_a_sotring_size)
	{
		set_new_cost(&cost);
		check_stack_cost(&cost, a, b);
		cost_optimization(&cost);
		excute_cost(&cost, &a, &b);
	}
	end_sort(&a, a, a, stack_a_sotring_size);
	push_swap_stack_free(a, stack_a_sotring_size);
	push_swap_stack_free(b, stack_a_sotring_size);
}
