/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:27:11 by kipark            #+#    #+#             */
/*   Updated: 2022/04/27 21:22:19 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_list_head_colum(char *head_str)
{
	int	length;

	length = 0;
	while (head_str[length] != '\0')
		length++;
	return (length);
}

int	get_list_head_row(t_list *list_head)
{
	int	length;

	length = 0;
	while (list_head != NULL)
	{
		length++;
		list_head = list_head->next;
	}
	return (length);
}
