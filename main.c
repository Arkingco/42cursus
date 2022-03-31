/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:11:58 by kipark            #+#    #+#             */
/*   Updated: 2022/03/31 21:41:00 by kipark           ###   ########seoul.kr  */
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

int main()
{
	t_stack *head = NULL;

	stack_operations_add(&head, 10);
	stack_operations_add(&head, 20);
	stack_operations_add(&head, 30);
	
	show_stack_next(head);
	printf("---------\n");
	show_stack_previuos(head, head);
}
