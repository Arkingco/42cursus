/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:14:40 by kipark            #+#    #+#             */
/*   Updated: 2022/01/07 19:45:24 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char *gnl_set_line(char *static_line, int fd)
{
	char	buffer[BUFFER_SIZE];
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (gnl_strchr(buffer, '\n') != 0)
		{
			static_line = gnl_strjoin(static_line, buffer, BUFFER_SIZE);
			break;
		}
		static_line = gnl_strjoin(static_line, buffer, BUFFER_SIZE);
		gnl_buffer_clear(buffer);
	}
	return (static_line);
}

char *gnl_set_return_line(char *static_line, char *return_line)
{
	int return_line_length;
	int i;

	return_line_length = gnl_strchr(static_line, '\n');
	if (return_line_length == 0)
		return_line_length = gnl_strlen(static_line);
	return_line = malloc(sizeof(char) * return_line_length + 1);
	if (return_line == 0)
		return (0);
	i = 0;
	while (i < return_line_length)
	{
		return_line[i] = static_line[i];
		++i;
	}
	return_line[i] = '\0';
	return (return_line);
}

char *gnl_set_static_line(char *static_line)
{
	char	*new_static_line;
	int		new_static_line_length;
	int		static_line_length;
	int		static_strchr_length;
	int		i;

	i = 0;
	static_strchr_length = gnl_strchr(static_line, '\n');
	if (static_strchr_length == 0)
		static_strchr_length = gnl_strlen(static_line);
	static_line_length = gnl_strlen(static_line);
	new_static_line_length = static_line_length - static_strchr_length;
	new_static_line = malloc(sizeof(char) * new_static_line_length + 1);
	if (new_static_line == 0)
		return (0);
	while (i < new_static_line_length)
	{
		new_static_line[i] = static_line[i + static_strchr_length];
		++i;
	}
	new_static_line[i] = '\0';
	free(static_line);
	return (new_static_line);
}

char *get_next_line(int fd)
{
	char			*return_line;
	static char		*static_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (static_line == NULL || gnl_strchr(static_line, '\n') == 0)
	{ 
		static_line = gnl_set_line(static_line, fd);
		if (static_line == NULL)
		{
			free(static_line);
			return (0);
		}
	}
	return_line = NULL;
	return_line = gnl_set_return_line(static_line, return_line);
	static_line = gnl_set_static_line(static_line);
	if (return_line[0] == '\0')
	{
		free(return_line);
		free(static_line);
		return (0);
	}
	return (return_line);
}