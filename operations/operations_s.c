/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:00:07 by kipark            #+#    #+#             */
/*   Updated: 2022/04/17 15:23:56 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static void	s_swap(t_stack *ab)
{
	int	temp;

	if (ab->next == NULL)
		return ;
	temp = ab->node_value;
	ab->node_value = ab->next->node_value;
	ab->next->node_value = temp;
}

void	sa(t_stack *a)
{
	write(1, "sa\n", 3);
	return (s_swap(a));
}

void	sb(t_stack *b)
{
	write(1, "sb\n", 3);
	return (s_swap(b));
}

void	ss(t_stack *a, t_stack *b)
{
	s_swap(a);
	s_swap(b);
	write(1, "ss\n", 3);
	return ;
}
