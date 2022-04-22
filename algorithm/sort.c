/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:24:54 by kipark            #+#    #+#             */
/*   Updated: 2022/04/22 17:17:37 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_sort_third(t_stack **a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*a)->node_value;
	mid = (*a)->next->node_value;
	bottom = (*a)->next->next->node_value;
	if (top > mid && mid > bottom && top > bottom)
	{
		sa(*a);
		rra(a);
	}
	else if (top > mid && bottom > mid && top > bottom)
		ra(a);
	else if (mid > top && mid > bottom && bottom > top)
	{
		sa(*a);
		ra(a);
	}
	else if (top > mid && bottom > mid && bottom > top)
		sa(*a);
	else if (mid > top && mid > bottom && top > bottom)
		rra(a);
}

void	stack_sort_second(t_stack **a)
{
	int	top;
	int	bottomtom;

	top = (*a)->node_value;
	bottomtom = (*a)->next->node_value;
	if (top > bottomtom)
	{
		ra(a);
	}
}

void	swap(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int	partition(int *arr, int left, int right)
{
	int	pivot_position;
	int	pivot;
	int	i;
	int	j;

	pivot = arr[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (arr[j] < pivot)
		{
			++i;
			swap(arr, i, j);
		}
		j++;
	}
	pivot_position = i + 1;
	swap(arr, pivot_position, right);
	return (pivot_position);
}

void	sort_arr(int *arr, int left, int right)
{
	int	pivot_position;

	if (left >= right)
		return ;
	pivot_position = partition(arr, left, right);
	sort_arr(arr, left, pivot_position - 1);
	sort_arr(arr, pivot_position + 1, right);
}
