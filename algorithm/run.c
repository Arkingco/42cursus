/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:27:34 by kipark            #+#    #+#             */
/*   Updated: 2022/04/19 21:32:14 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void excute_cost(t_cost *cost, t_stack **a, t_stack **b)
{
	int count;

	count = 0;
	while(count++ < cost->rr)
		r_rr(a, b);
	count = 0;
	while(count++ < cost->ra)
		r_ra(a);
	count = 0;
	while(count++ < cost->rb)
		r_rb(b);
	count = 0;
	while(count++ < cost->rrr)
		rr_rrr(a, b);
	count = 0;
	while(count++ < cost->rra)
		rr_rra(a);
	count = 0;
	while(count++ < cost->rrb)
		rr_rrb(b);
	p_pa(a, b);
}

void cost_optimization(t_cost *cost)
{
	if(cost->ra > 0)
	{
		if(cost->rb > 0)
		{
			while(cost->ra != 0 && cost->rb != 0)
			{
				cost->ra = cost->ra - 1;
				cost->rb = cost->rb - 1;
				cost->rr = cost->rr + 1;
			}
		}
	}
	else if(cost -> rra > 0)
	{
		if(cost->rrb > 0)
		{
			while(cost->rra != 0 && cost->rrb != 0)
			{
				cost->rra = cost->rra - 1;
				cost->rrb = cost->rrb - 1;
				cost->rrr = cost->rrr + 1;
			}
		}
	}
}

void stack_push_all_pb(t_stack **a, t_stack **b)
{
	int stack_length;

	stack_length = get_stack_length(*a, *a);
	if(stack_length <= 3)
		return ;
	while(1)
	{
		p_pb(a, b);
		stack_length--;
		if(stack_length <= 3)
			return ;
	}
}

void show_stack(t_stack *a, t_stack *b, char *flag)
{
	int i;
	t_stack *a_head = a;
	t_stack *b_head = b;
	
	printf("------------%s--------------\n", flag);
	i = 1;
	while(1)
	{
		if(a == NULL)
			return ;
		printf("--a : [%d] %ld\n", i, a->node_value);
		if(a->next == a_head)
			break;
		a = a->next;
		++i;
	}
	printf("-------b------\n");
	i = 1;
	while(1)
	{
		if(b == NULL)
			return ;
		printf("--b : [%d] %ld\n", i, b->node_value);
		if(b->next == b_head)
			break;
		b = b->next;
		++i;
	}
	printf("\n\n");
}

void stack_sort_third(t_stack **a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*a)->node_value;
	mid = (*a)->next->node_value;
	bottom = (*a)->next->next->node_value;
	if (top > mid && mid > bottom && top > bottom)
	{
		s_sa(*a);
		rr_rra(a);
	}
	else if (top > mid && bottom > mid && top > bottom)
		r_ra(a);
	else if (mid > top && mid > bottom && bottom > top)
	{
		s_sa(*a);
		r_ra(a);
	}
	else if (top > mid && bottom > mid && bottom > top)
		s_sa(*a);
	else if (mid > top && mid > bottom && top > bottom)
		rr_rra(a);
}

void stack_sort_second(t_stack **a)
{
	int top;
	int bottomtom;
	
	top = (*a)->node_value;
	bottomtom = (*a)->next->node_value;
	if(top > bottomtom)
	{
		r_ra(a);
	}
}

void soft_sort(t_stack **a)
{
	int stack_length;

	stack_length = get_stack_length(*a, *a);
	if(stack_length == 2)
	{
		stack_sort_second(a);
	}
	else if(stack_length == 3)
	{
		stack_sort_third(a);
	}
	else 
	{
		return ;
	}
}

void end_sort_stack_a(t_stack *a, t_stack *head, int target_a, int stack_length)
{
	t_cost cost;
	int length;
	int count;

	count = 0;
	length = 0;
	set_new_cost(&cost);
	while(1)
	{
		if(a->node_value == target_a)
		{
			cost.ra = length;
			cost.rra = stack_length - length;
			break;
		}
		if(a->next == head)
			break;
		a = a->next;
		length++;
	}
	if(cost.ra > cost.rra)
		cost.ra = -1;
	if(cost.rra > cost.ra)
		cost.rra = -1;
	excute_cost(&cost, &a, NULL);
}

int find_min_value_stack(t_stack *a, t_stack *head)
{
	long int min_value;

	min_value = INT64_MAX;
	while(1)
	{
		if(min_value > a->node_value)
			min_value = a->node_value;
		if(a->next == head)
			break;
		a = a->next;
	}
	return ((int)min_value);
}

int check_arr_is_sort(t_stack *a, t_stack *head)
{
	long int node_value;

	node_value = INT64_MIN;
	while(1)
	{
		if(a->node_value < node_value)
			return (0);
		node_value = a->node_value;
		if(a->next == head)
			break;
		a = a->next;
	}
	return (1);
}

void algorithm_run(t_stack *a, t_stack *b)
{
	t_cost cost;
	int stack_a_sotring_size;
	int min_value_stack;

	if(check_arr_is_sort(a, a))
		return ;
	stack_a_sotring_size = get_stack_length(a, a);
	stack_push_all_pb(&a, &b);
	soft_sort(&a);
	while(get_stack_length(a, a) != stack_a_sotring_size)
	{
		set_new_cost(&cost);
		check_stack_cost(&cost, a, b);
		cost_optimization(&cost);
		excute_cost(&cost, &a, &b);
	}
	min_value_stack = find_min_value_stack(a, a);
	end_sort_stack_a(a, a, min_value_stack, stack_a_sotring_size);
}