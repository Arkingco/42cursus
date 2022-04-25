/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:11:23 by kipark            #+#    #+#             */
/*   Updated: 2022/04/23 20:14:54 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	check_argv_duplicate(long int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != INT64_MIN)
	{
		j = i + 1;
		while (arr[j] != INT64_MIN)
		{
			if (arr[i] == arr[j])
				print_error(1);
			++j;
		}
		++i;
	}
}

static void	set_argv_indexing(long int *arr, int arr_length)
{
	int	i;
	int	j;
	int	count;
	int	*arr_temp;

	arr_temp = malloc(sizeof(long int) * (arr_length + 1));
	i = 0;
	while (arr[i] != INT64_MIN)
	{
		j = 0;
		count = 1;
		while (arr[j] != INT64_MIN)
		{
			if (i != j && arr[i] > arr[j])
				count++;
			++j;
		}
		arr_temp[i] = count;
		++i;
	}
	j = -1;
	while (j++ < i)
		arr[j] = arr_temp[j];
	push_swap_free((void *)&arr_temp);
}

static long int	*set_new_arr(long int *arr, int *arr_length, int arr_idx)
{
	long int	*new_arr;
	int			i;
	int			new_arr_size;

	new_arr_size = (*arr_length) * 4 + 4;
	*arr_length = new_arr_size;
	new_arr = malloc(sizeof(long int) * new_arr_size);
	if (new_arr == NULL)
		print_error(1);
	i = 0;
	while (i < arr_idx)
	{
		new_arr[i] = arr[i];
		i++;
	}
	push_swap_free((void *)&arr);
	return (new_arr);
}

static long int	*set_arr(long int *arr, int argc, char **argv, int *length)
{
	int			i;
	int			idx;
	int			arr_idx;
	int			arr_size_max;
	long int	*parse_pointer;

	idx = 1;
	arr_idx = 0;
	arr_size_max = 0;
	while (idx < argc)
	{
		parse_pointer = parser(argv[idx]);
		i = 0;
		while (parse_pointer[i] != INT64_MIN)
		{
			if (arr_idx >= arr_size_max - 1)
				arr = set_new_arr(arr, &arr_size_max, arr_idx);
			arr[arr_idx++] = parse_pointer[i++];
		}
		push_swap_free((void *)&parse_pointer);
		idx++;
	}
	arr[arr_idx] = INT64_MIN;
	*length = arr_idx;
	return (arr);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	long int	*arr;
	int			arr_length;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	arr_length = 0;
	arr = NULL;
	arr = set_arr(arr, argc, argv, &arr_length);
	check_argv_duplicate(arr);
	set_argv_indexing(arr, arr_length);
	while (--arr_length >= 0)
		stack_operations_add(&a, arr[arr_length]);
	run_algorithm(a, b);
	free(arr);
}
