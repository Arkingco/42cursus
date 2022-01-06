/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:27:48 by kipark            #+#    #+#             */
/*   Updated: 2022/01/06 14:28:06 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int gnl_strchr(char *s, char word)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		if(s[i] == word)
			return (i+1);
		++i;
	}
	return (0);
}

int gnl_strlen(char *s)
{
	int i;

	i = 0;
	if(s == 0)
		return (0);
	while(s[i] != '\0')
		++i;
	return(i);
}

char *gnl_strjoin(char *static_line, char *buffer, int buffer_length)
{
	char	*new_line;
	int	get_line_length;
	int i;

	if(buffer == NULL || buffer_length < 1)
		return (static_line);
	i = 0;
	get_line_length = gnl_strlen(static_line);
	new_line = malloc(sizeof(char) * (get_line_length + buffer_length + 1));
	if(new_line == NULL)
		return (0);
	while(i < get_line_length)
	{
		new_line[i] = static_line[i];
		++i;
	}
	while(i < buffer_length + get_line_length)
	{
		new_line[i] = buffer[i - get_line_length];
		++i;
	}
	new_line[i] = '\0';
	free(static_line);
	return (new_line);
}