/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:03:49 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:49 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	lst_size = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		lst_size++;
	}
	return (lst_size);
}
