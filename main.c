/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:11:58 by kipark            #+#    #+#             */
/*   Updated: 2022/04/04 22:18:30 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"


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

void set_argv_arr(long int *argv_arr, int argc, char **argv)
{
	int idx;
	int arr_idx;
	long int *parse_pointer;
	int i;

	idx = 1;
	arr_idx = 0;
	while(idx < argc)
	{
		parse_pointer = parser(argv[idx]);
		i = 0;
		while(parse_pointer[i] != INT64_MIN)
			argv_arr[arr_idx++] = parse_pointer[i++];
		free(parse_pointer);
		parse_pointer = 0;
		idx++;
	}
	argv_arr[arr_idx] = INT64_MIN;
}

int main(int argc, char **argv)
{
	t_stack *head = NULL;

	stack_operations_add(&head, 10);
	stack_operations_add(&head, 20);
	stack_operations_add(&head, 30);
	
	// show_stack_next(head);
	// printf("---------\n");
	// show_stack_previuos(head, head);

	// char **a = push_swap_parser_split("1233123", ' ');			0
	// char **b = push_swap_parser_split("+1231123", ' ');			0
	// char **c = push_swap_parser_split("-4123", ' ');				0
	// char **a1 = push_swap_parser_split("++123+3123", ' ');		1
	// char **b1 = push_swap_parser_split("--1231123", ' ');		1
	// char **c1 = push_swap_parser_split("41+23", ' ');			1
	// char **a2 = push_swap_parser_split("123123 a", ' ');			1
	// char **b2 = push_swap_parser_split("+1231123 ", ' ');		0
	// char **c2 = push_swap_parser_split("4123 123 4123", ' ');	0
	// printf("\n\n\n %d %d %d %d %d %d %d %d %d", paser_error(a), paser_error(b), paser_error(c),  paser_error(a1), paser_error(b1), paser_error(c1),  paser_error(a2), paser_error(b2), paser_error(c2));

	// long int *a = parser(argv[argc-1]);
	// if(a != NULL)
	// 	for(int i=0; a[i] != INT64_MIN; ++i){
	// 		printf("%ld \n", a[i]);
	// 	}

	// char **a = push_swap_parser_split("123 41 312 ", ' ');




	long int *argv_arr;
	
	if(argc < 1)
		return (0);

	argv_arr = malloc(sizeof(long int) * (501 + 1));
	set_argv_arr(argv_arr, argc, argv);
	
	// some algorithm

	//	
	for(int i=0; argv_arr[i] != INT64_MIN; ++i)
	{
		printf("%ld\n", argv_arr[i]);
	}
	free(argv_arr);
}