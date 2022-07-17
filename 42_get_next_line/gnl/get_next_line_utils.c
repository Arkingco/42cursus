/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:27:48 by kipark            #+#    #+#             */
/*   Updated: 2022/01/15 23:30:35 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	gnl_strchr(char *line, char word)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == word)
			return (i + 1);
		++i;
	}
	return (0);
}

int	gnl_strlen(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] != '\0')
		++i;
	return (i);
}

void	gnl_free_char_pointer(char **pointer)
{
	if(*pointer == 0)
		return ;
	free(*pointer);
	*pointer = NULL;
	return ;
}
