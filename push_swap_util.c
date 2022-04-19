/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:13 by kipark            #+#    #+#             */
/*   Updated: 2022/04/19 15:59:14 by kipark           ###   ########.fr       */
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


void push_swap_stack_free(t_stack **stack, t_stack **stack_head)
{
	
	while(1)
	{
		if((*stack)->next == (*stack_head))
			return ;
	}
}