/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:11:58 by kipark            #+#    #+#             */
/*   Updated: 2022/04/18 19:59:02 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

#define ARGV_ARR_SIZE 500

void check_argv_duplicate(long int *argv_arr)
{
	int i;
	int j;
	
	i = 0;
	while(argv_arr[i] != INT64_MIN)
	{
		j = i + 1;
		while(argv_arr[j] != INT64_MIN)
		{
			if(argv_arr[i] == argv_arr[j])
				error_exit();
			++j;
		}
		++i;
	}
}

void set_argv_arr(long int *argv_arr, int argc, char **argv)
{
	int idx;
	int arr_idx;
	long int *parse_pointer;
	int i;

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
}

void push_swap_algorithm(long int *argv_arr)
{
	argv_arr = 0;
}

// exit()할때 malloc 알아서 풀어줌??
// 프로세스에 할당되어있는 malloc들이 프로세스 자체를 없애버리니까 같이 날라간다 고 하네여~
int main(int argc, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	long int *argv_arr;
	


	if(argc < 1)
		return (0);
	argv_arr = malloc(sizeof(long int) * (ARGV_ARR_SIZE + 1));
	argv = NULL;
	set_argv_arr(argv_arr, argc, argv);
	check_argv_duplicate(argv_arr);

	for(int i=0; argv_arr[i] != INT64_MIN; ++i)
	{
		stack_operations_add(&a, argv_arr[i]);
	}
	
	algorithm_run(a, b);
	
	free(argv_arr);
}