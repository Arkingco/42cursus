/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:11:23 by kipark            #+#    #+#             */
/*   Updated: 2022/04/20 21:40:17 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

#define ARGV_ARR_SIZE 500

void	check_argv_duplicate(long int *argv_arr)
{
	int	i;
	int	j;

	i = 0;
	while (argv_arr[i] != INT64_MIN)
	{
		j = i + 1;
		while (argv_arr[j] != INT64_MIN)
		{
			if (argv_arr[i] == argv_arr[j])
				error_exit(1);
			++j;
		}
		++i;
	}
}

void	set_argv_int_arr(long int *argv_arr, int argc, char **argv, int *length)
{
	int			i;
	int			idx;
	int			arr_idx;
	long int	*parse_pointer;

	idx = 1;
	arr_idx = 0;
	while (idx < argc)
	{
		parse_pointer = parser(argv[idx]);
		i = 0;
		while (parse_pointer[i] != INT64_MIN)
		{
			argv_arr[arr_idx++] = parse_pointer[i++];
		}
		free(parse_pointer);
		parse_pointer = 0;
		idx++;
	}
	argv_arr[arr_idx] = INT64_MIN;
	*length = arr_idx;
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	long int	*argv_arr;
	int			arr_length;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	argv_arr = malloc(sizeof(long int) * (ARGV_ARR_SIZE + 1));
	arr_length = 0;
	set_argv_int_arr(argv_arr, argc, argv, &arr_length);
	check_argv_duplicate(argv_arr);
	while (--arr_length != -1)
		stack_operations_add(&a, argv_arr[arr_length]);
	algorithm_run(a, b);
	free(argv_arr);
}
