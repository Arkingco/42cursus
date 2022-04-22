/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:13 by kipark            #+#    #+#             */
/*   Updated: 2022/04/22 16:33:32 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_swap_memset(void *arr, int arr_length)
{
	int				i;
	unsigned char	*pointer;

	i = 0;
	pointer = (unsigned char *)arr;
	while (i < arr_length)
	{
		pointer[i] = 0;
		++i;
	}
}

void	push_swap_free(void **pointer)
{
	free(*pointer);
	*pointer = 0;
}

void	push_swap_stack_free(t_stack *stack, int stack_length)
{
	t_stack	*temp_head;
	int		length;

	length = 0;
	if (stack == NULL)
		return ;
	while (length < stack_length)
	{
		temp_head = stack;
		stack = stack->next;
		free(temp_head);
		length++;
	}
}

void	push_swap_double_arr_free(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		++i;
	}
	free(pointer[i]);
	free(pointer);
}
