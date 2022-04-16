/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:22:40 by kipark            #+#    #+#             */
/*   Updated: 2022/04/16 19:28:07 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

/*
// wrong code 
void check_stack_cost_b(t_cost *cost, t_stack *b)
{
	int top_depth;
	int bottom_depth;
	t_stack *head;
	
	top_depth = 1;
	
	head = b;
	if (b->next == head)
		cost->top_down[top_depth] = top_depth;
	while(b->next != head)
	{
		cost->top_down[top_depth] = top_depth;
		top_depth++;
		b = b->next;
	}
	bottom_depth = top_depth;
	while(bottom_depth != 0)
	{
		cost->bottom_up[bottom_depth] = bottom_depth + 1;
		bottom_depth--;
	}
}
*/

int get_stack_length(t_stack *stack)
{
	int length;
	t_stack *head;

	if(head == NULL)
		return (0);
	length = 1;
	head = stack;
	while(stack->next != head)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}


// 스택 a에 top에 오게 하도록 만들어야 하는게 제일 효율적임
// 이 아니라 그냥 무조건 위치가 정해 져 있음 
// 이 위치를 특정하는게 사실상 불가능함 그냥 정렬을 하거나 가능하다면 나름 근사값으로 처리를 하는 수 밖에 없는데 일단 흐음..
void check_stack_cost(t_cost *cost, t_stack *a, t_stack *b)
{
	t_stack *b_head;
	t_cost	new_cost;

	b_head = b;
	cost->cost_value = INT32_MAX;
	while(b->next != b_head)
	{
		set_new_cost(&new_cost);
		new_cost.target_b = b->node_value;
		new_cost.target_a = return_target_in_a(a, b->node_value);
		find_cost_a_b(&new_cost, a, b);
		find_min_cost(cost, &new_cost);
		b = b->next;
	}
}

// drinking cording ~
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
		cost = new_cost;
}

// return target
int return_target_in_a(t_stack *a, int b_node)
{
	int *arr;
	int target;
	int array_size;

	array_size = get_stack_length(a) + 1;
	arr = malloc(sizeof(int) * array_size);
	if(arr == NULL)
		print_error();
	set_arr(a, arr, b_node);
	sort_arr_to_merge(arr);
	target = find_target_in_arr(arr, array_size, b_node);
	push_swap_free(arr);
	return (target);
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

void set_cost_to_target_in_stack(t_cost *new_cost, t_stack *stack, int ab)
{
	t_stack *stack_head;
	int stack_length;
	int length;

	stack_length = get_stack_length(stack);
	length = 0;
	stack_head = stack;
	while(stack->next != stack_head)
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
		stack = stack->next;
	}
}

void set_arr(t_stack *a, int *arr, int b_node)
{
	t_stack *a_head;
	int i;

	a_head = a;
	i = 0;
	while(a->next != a_head)
	{
		arr[i] = a->node_value;
		a = a->next;
		++i;
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
			return (array_size % (i + 1));			
		}
		++i;
	}
}