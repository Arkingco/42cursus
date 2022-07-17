/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:40:59 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:47 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	f(lst->content);
	while (lst->next != NULL)
	{
		lst = lst->next;
		f(lst->content);
	}
}
