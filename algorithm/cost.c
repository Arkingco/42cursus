/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:22:40 by kipark            #+#    #+#             */
/*   Updated: 2022/04/22 16:24:52 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	set_cost_key(t_cost *new_cost, t_stack *stack, t_stack *head, int ab)
{
	int		stack_length;
	int		length;

	stack_length = get_stack_length(stack, stack);
	length = 0;
	while (1)
	{
		if (stack->node_value == new_cost->target_a && ab)
		{
			new_cost->ra = length;
			new_cost->rra = stack_length - length;
			break ;
		}
		else if (stack->node_value == new_cost->target_b && !ab)
		{
			new_cost->rb = length;
			new_cost->rrb = stack_length - length;
			break ;
		}
		if (stack->next == head)
			break ;
		stack = stack->next;
		length++;
	}
}

void	find_cost_a_b(t_cost *new_cost, t_stack *a, t_stack *b)
{
	set_cost_key(new_cost, a, a, STACK_A);
	set_cost_key(new_cost, b, b, STACK_B);
	if (new_cost->ra > new_cost->rra)
	{
		new_cost->ra = -1;
		new_cost->cost_value += new_cost->rra;
	}
	else
	{
		new_cost->rra = -1;
		new_cost->cost_value += new_cost->ra;
	}
	if (new_cost->rb > new_cost->rrb)
	{
		new_cost->rb = -1;
		new_cost->cost_value += new_cost->rrb;
	}
	else
	{
		new_cost->rrb = -1;
		new_cost->cost_value += new_cost->rb;
	}
}

int	return_target_in_a(t_stack *a, int b_node)
{
	int	*arr;
	int	target;
	int	array_size;

	array_size = get_stack_length(a, a) + 1;
	arr = malloc(sizeof(int) * array_size);
	if (arr == NULL)
		print_error(1);
	set_arr(a, arr, b_node);
	sort_arr(arr, 0, array_size - 1);
	target = find_target_in_arr(arr, array_size, b_node);
	push_swap_free((void *)&arr);
	return (target);
}

void	check_stack_cost(t_cost *cost, t_stack *a, t_stack *b)
{
	t_stack	*b_head;
	t_cost	new_cost;

	if (b == NULL || a == NULL)
		return ;
	b_head = b;
	cost->cost_value = INT32_MAX;
	while (1)
	{
		set_new_cost(&new_cost);
		new_cost.target_b = b->node_value;
		new_cost.target_a = return_target_in_a(a, b->node_value);
		find_cost_a_b(&new_cost, a, b_head);
		find_min_cost(cost, &new_cost);
		if (b->next == b_head)
			break ;
		b = b->next;
	}
}
