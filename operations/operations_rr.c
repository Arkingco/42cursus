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

static void	rr_works(t_stack **head)
{
	*head = (*head)->previous;
	return ;
}

void	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	return (rr_works(a));
}

void	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	return (rr_works(b));
}

void	rrr(t_stack **a, t_stack **b)
{
	rr_works(a);
	rr_works(b);
	write(1, "rrr\n", 4);
	return ;
}
