/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:29:48 by kipark            #+#    #+#             */
/*   Updated: 2022/04/20 21:17:32 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void	show_stack(t_stack *a, t_stack *b, char *flag)
// {
// 	int i;
// 	t_stack *a_head = a;
// 	t_stack *b_head = b;

// 	printf("------------%s--------------\n", flag);
// 	i = 1;
// 	while(1)
// 	{
// 		if(a == NULL)
// 			return ;
// 		printf("--a : [%d] %ld\n", i, a->node_value);
// 		if(a->next == a_head)
// 			break;
// 		a = a->next;
// 		++i;
// 	}
// 	printf("-------b------\n");
// 	i = 1;
// 	while(1)
// 	{
// 		if(b == NULL)
// 			return ;
// 		printf("--b : [%d] %ld\n", i, b->node_value);
// 		if(b->next == b_head)
// 			break;
// 		b = b->next;
// 		++i;
// 	}
// 	printf("\n\n");
// }