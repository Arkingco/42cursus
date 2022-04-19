/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:13 by kipark            #+#    #+#             */
/*   Updated: 2022/04/19 22:21:50 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void push_swap_memset(void *arr, int arr_length)
{
	int i;
	unsigned char *pointer;

	i = 0;
	pointer = (unsigned char *)arr;
	while(i < arr_length)
	{
		pointer[i] = 0;
		++i;
	}
}

void push_swap_free(void **pointer)
{
	free(*pointer);
	*pointer = 0;
}

void push_swap_stack_free(t_stack **stack)
{
	t_stack *temp_head;

	
	if(*stack == NULL)
		return ;
	while((*stack)->next != NULL)
	{
		temp_head = (*stack)->next;
		free((*stack));
		*stack = 0;
		*stack = temp_head;
	}
	*stack = 0;
}

void push_swap_double_arr_free(char **pointer)
{
	int i;

	i = 0;
	while(pointer[i])
	{
		free(pointer[i]);
		++i;
	}
}