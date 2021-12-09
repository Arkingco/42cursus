/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:47:58 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:48 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_lst_next;

	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
		return (0);
	new_lst_next = new_lst;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_lst_next->next = ft_lstnew(f(lst->content));
		if (new_lst_next->next == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		new_lst_next = new_lst_next->next;
	}
	return (new_lst);
}
