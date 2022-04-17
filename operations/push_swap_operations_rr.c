/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:16:41 by kipark            #+#    #+#             */
/*   Updated: 2022/04/17 15:32:17 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static void rr_works(t_stack **head)
{
	*head = (*head)->previous;
	return ;
}

void rr_rra(t_stack **a)
{
	return (rr_works(a));
}

void rr_rrb(t_stack **b)
{
	return (rr_works(b));
}

void rr_rrr(t_stack **a, t_stack **b)
{
	rr_works(a);
	rr_works(b);
	return ;
}
