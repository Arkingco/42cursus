/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:27:11 by kipark            #+#    #+#             */
/*   Updated: 2022/05/02 10:46:48 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_parsed_str(char *parsed_str, char *head_str)
{
	int	idx;

	idx = 0;
	while (head_str[idx] != '\0')
	{
		parsed_str[idx] = head_str[idx];
		idx++;
	}
	parsed_str[idx] = '\0';
}

int	get_list_head_colum(char *head_str)
{
	int	length;

	length = 0;
	if (head_str == 0)
		return (0);
	while (head_str[length] != '\0')
		length++;
	if (head_str[length - 1] == '\n')
		length--;
	return (length);
}

int	get_list_head_row(t_list *list_head)
{
	int	length;

	length = 1;
	while (list_head != NULL)
	{
		length++;
		list_head = list_head->next;
	}
	return (length);
}

char	*so_long_strjoin(char *buffer)
{
	char	*new_line;
	int		i;
	int		buffer_length;

	i = 0;
	buffer_length = get_list_head_colum(buffer);
	if (buffer_length == 0)
		return (NULL);
	new_line = malloc(sizeof(char) * buffer_length + 1);
	if (new_line == NULL)
		return (0);
	while (i < buffer_length)
	{
		new_line[i] = buffer[i];
		++i;
	}
	new_line[i] = '\0';
	return (new_line);
}
