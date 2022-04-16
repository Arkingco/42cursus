/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:13 by kipark            #+#    #+#             */
/*   Updated: 2022/04/16 11:30:33 by kipark           ###   ########.fr       */
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