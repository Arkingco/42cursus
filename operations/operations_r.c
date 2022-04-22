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

static	void	r_works(t_stack **head)
{
	(*head)->next->stack_length = (*head)->stack_length;
	*head = (*head)->next;
	return ;
}

void	ra(t_stack **a)
{
	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	write(1, "ra\n", 3);
	return (r_works(a));
}

void	rb(t_stack **b)
{
	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	write(1, "rb\n", 3);
	return (r_works(b));
}

void	rr(t_stack **a, t_stack **b)
{
	r_works(a);
	r_works(b);
	write(1, "rr\n", 3);
	return ;
}
