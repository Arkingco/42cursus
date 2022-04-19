/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:22:40 by kipark            #+#    #+#             */
/*   Updated: 2022/04/19 15:22:36 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int get_stack_length(t_stack *stack, t_stack *head_stack)
{
	int length;
	t_stack *head;

	head = stack;
	if(head == NULL)
		return (0);
	length = 0;
	while(1)
	{
		length++;
		if(stack->next == head_stack)
			break;
		stack = stack->next;
	}
	return (length);
}

void set_arr(t_stack *a, int *arr, int b_node)
{
	t_stack *a_head;
	int i;

	a_head = a;
	if(a_head == NULL)
		return ;
	i = 0;
	while(1)
	{
		arr[i] = a->node_value;
		++i;
		if(a->next == a_head)
			break;
		a = a->next;
		
	}
	arr[i] = b_node;
}

int find_target_in_arr(int *arr, int array_size,int b_node)
{
	int i;

	i = 0;
	while(i < array_size)
	{
		if(arr[i] == b_node)
		{
			return (arr[(i + 1) % array_size]);			
		}
		++i;
	}
	return (-1);
}

void set_new_cost(t_cost *new_cost)
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

void find_min_cost(t_cost *cost, t_cost *new_cost)
{
	if(cost->cost_value > new_cost->cost_value)
	{
		cost->ra = new_cost->ra;
		cost->rra = new_cost->rra;
		cost->rb = new_cost->rb;
		cost->rrb = new_cost->rrb;
		cost->rr = new_cost->rr;
		cost->rrr =new_cost->rrr;
		cost->target_a = new_cost->target_a;
		cost->target_b = new_cost->target_b;
		cost->cost_value = new_cost->cost_value;
	}
}

int return_target_in_a(t_stack *a, int b_node)
{
	int *arr;
	int target;
	int array_size;

	array_size = get_stack_length(a, a) + 1;
	arr = malloc(sizeof(int) * array_size);
	if(arr == NULL)
		print_error();
	set_arr(a, arr, b_node);
	sort_arr(arr, array_size);
	target = find_target_in_arr(arr, array_size, b_node);
	push_swap_free((void *)&arr);
	return (target);
}

void set_cost_to_target_in_stack(t_cost *new_cost, t_stack *stack, int ab)
{
	t_stack *stack_head;
	int stack_length;
	int length;

	if(stack == NULL)
		return ;
	stack_length = get_stack_length(stack, stack);
	length = 0;
	stack_head = stack;
	while(1)
	{
		if(stack->node_value == new_cost->target_a && ab)
		{
			new_cost->ra = length;
			new_cost->rra = stack_length - length;
			break;
		}
		else if(stack->node_value == new_cost->target_b && !ab)
		{
			new_cost->rb = length;
			new_cost->rrb = stack_length - length;
			break;
		}
		++length;
		if(stack->next == stack_head)
			break;
		stack = stack->next;
	}
}


void find_cost_a_b(t_cost *new_cost, t_stack *a, t_stack *b)
{
	set_cost_to_target_in_stack(new_cost, a, STACK_A);
	set_cost_to_target_in_stack(new_cost, b, STACK_B);
	if(new_cost->ra > new_cost->rra)
	{
		new_cost->ra = -1;
		new_cost->cost_value += new_cost->rra;
	}
	else
	{
		new_cost->rra = -1;
		new_cost->cost_value += new_cost->ra;
	}
	if(new_cost->rb > new_cost->rrb)
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

void check_stack_cost(t_cost *cost, t_stack *a, t_stack *b)
{
	t_stack *b_head;
	t_cost	new_cost;

	if(b == NULL)
		return ;
	b_head = b;
	cost->cost_value = INT32_MAX;
	while(1)
	{
		set_new_cost(&new_cost);
		new_cost.target_b = b->node_value;
		new_cost.target_a = return_target_in_a(a, b->node_value);
		find_cost_a_b(&new_cost, a, b_head);
		find_min_cost(cost, &new_cost);
		if(b->next == b_head)
			break;
		b = b->next;
	}
}
