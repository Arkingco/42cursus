/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:18:19 by kipark            #+#    #+#             */
/*   Updated: 2022/04/17 15:30:11 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static void r_works(t_stack **head)
{
	*head = (*head)->next;
	return ;
}

void r_ra(t_stack **a)
{
	if(*a == NULL)
		return ;
	if((*a)->next == NULL)
		return ;
	return (r_works(a));
}

void r_rb(t_stack **b)
{
	if(*b == NULL)
		return ;
	if((*b)->next == NULL)
		return ;
	return (r_works(b));
}

void r_rr(t_stack **a, t_stack **b)
{
	r_ra(a);
	r_rb(b);
	return ;
}