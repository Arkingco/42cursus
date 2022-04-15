/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:22:40 by kipark            #+#    #+#             */
/*   Updated: 2022/04/15 21:58:13 by kipark           ###   ########.fr       */
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
void check_stack_cost_a(t_cost *cost, t_stack *a, t_stack *b)
{
	// 스택 a의 원소를 중심으로 하는 배열 a를 만들기
	t_stack *b_head;
	int *arr;
	int target;

	b_head = b;
	while(b->next != b_head)
	{
		arr = make_array_a(a, b);

		find_cost_a_b(cost, target, b->node_value);
		b = b->next;
	}
}

int make_array_a(t_stack *a, t_stack *b)
{
	int *arr;
	int target;
	int array_size;

	array_size = get_stack_length(a) + 1;
	arr = malloc(sizeof(int) * array_size);
	if(arr == NULL)
		print_error();
	set_arr(a, arr);
	sort_arr_to_merge(arr);
	target = find_target_in_arr(arr, array_size, b->node_value);
	find_target_in_a(a, target);

	free(arr);
	arr = 0;
}

int find_target_in_a(t_stack *a, int target)
{
	
	while()	
}
void set_arr(t_stack *a, int *arr)
{
	t_stack *a_head;
	int i;

	a_head = a;
	i = 0;
	while(a->next != a_head)
	{
		arr[i] = a->node_value;
		a = a->next;		
	}
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