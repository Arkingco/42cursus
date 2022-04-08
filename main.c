/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:11:58 by kipark            #+#    #+#             */
/*   Updated: 2022/04/08 21:34:26 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

#define ARGV_ARR_SIZE 500

void show_stack_next(t_stack *head)
{
	if(head == NULL)
		return ;
	while(1)
	{
		printf("stack %ld \n", head->node_value);
		if(head == head->next || head->next == NULL)
			break;
		head = head->next;
	}
}

void show_stack_previuos(t_stack *head, t_stack *stop_head)
{
	if(head == NULL)
		return ;
	while(1)
	{
		printf("stack %ld \n", head->node_value);
		head = head->previous;
		if(head == stop_head || head == NULL)
			break ;
	}
}

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
			if (arr_idx == ARGV_ARR_SIZE)
				error_exit();
		}
		free(parse_pointer);
		parse_pointer = 0;
		idx++;
	}
	argv_arr[arr_idx] = INT64_MIN;
}

void push_swap_algorithm(long int *argv_arr)
{
	
}

// exit()할때 malloc 알아서 풀어줌??
// 프로세스에 할당되어있는 malloc들이 프로세스 자체를 없애버리니까 같이 날라간다 고 하네여~
int main(int argc, char **argv)
{
	// t_stack *head = NULL;

	// stack_operations_add(&head, 10);
	// stack_operations_add(&head, 20);
	// stack_operations_add(&head, 30);
	// i m new kipark
		
	long int *argv_arr;

	if(argc < 1)
		return (0);
	argv_arr = malloc(sizeof(long int) * (ARGV_ARR_SIZE + 1));
	set_argv_arr(argv_arr, argc, argv);
	check_argv_duplicate(argv_arr);
	// some algorithm
	push_swap_algorithm(argv_arr);
	//
	for(int i=0; argv_arr[i] != INT64_MIN; ++i)
	{
		printf("%ld\n", argv_arr[i]);
	}
	free(argv_arr);

	printf("%d", INT32_MIN);
}