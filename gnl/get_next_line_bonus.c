/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:14:40 by kipark            #+#    #+#             */
/*   Updated: 2022/01/15 23:30:35 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

static char	*gnl_strjoin(char *static_line, char *buffer, int buffer_length)
{
	char	*new_line;
	int		static_line_length;
	int		i;

	i = 0;
	static_line_length = gnl_strlen(static_line);
	new_line = malloc(sizeof(char) * (static_line_length + buffer_length + 1));
	if (new_line == NULL)
		return (0);
	while (i < static_line_length)
	{
		new_line[i] = static_line[i];
		++i;
	}
	while (i < buffer_length + static_line_length)
	{
		new_line[i] = buffer[i - static_line_length];
		++i;
	}
	new_line[i] = '\0';
	gnl_free_char_pointer(&static_line);
	return (new_line);
}

static char	*gnl_set_line(char *static_line, int fd)
{
	char	*buffer;
	int		read_byte;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(buffer == NULL)
		return (0);
	read_byte = read(fd, buffer, BUFFER_SIZE);
	while (read_byte > 0)
	{
		if (gnl_strchr(buffer, '\n'))
		{
			static_line = gnl_strjoin(static_line, buffer, read_byte);
			break ;
		}
		static_line = gnl_strjoin(static_line, buffer, read_byte);
		read_byte = read(fd, buffer, BUFFER_SIZE);
	}
	gnl_free_char_pointer(&buffer);
	return (static_line);
}

static char	*gnl_set_return_line(char *static_line)
{
	char	*return_line;
	int		return_line_length;
	int		i;

	if (gnl_strlen(static_line) == 0)
		return (0);
	return_line_length = gnl_strchr(static_line, '\n');
	if (return_line_length == 0)
		return_line_length = gnl_strlen(static_line);
	return_line = malloc(sizeof(char) * (return_line_length + 1)); 
	if (return_line == NULL)
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

static char	*gnl_set_static_line(char *static_line)
{
	char	*new_static_line;
	int		new_static_length;
	int		static_strchr_length;
	int		i;

	i = 0;
	static_strchr_length = gnl_strchr(static_line, '\n');
	if (static_strchr_length == 0)
		static_strchr_length = gnl_strlen(static_line);
	new_static_length = gnl_strlen(static_line) - static_strchr_length;
	new_static_line = malloc(sizeof(char) * (new_static_length + 1));
	if (new_static_line == 0)
		return (0);
	while (i < new_static_length)
	{
		new_static_line[i] = static_line[i + static_strchr_length];
		++i;
	}
	new_static_line[i] = '\0';
	gnl_free_char_pointer(&static_line);
	return (new_static_line);
}

char	*get_next_line(int fd)
{
	char			*return_line;
	static char		*static_line[OPEN_MAX + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (0);
	static_line[fd] = gnl_set_line(static_line[fd], fd);
	return_line = gnl_set_return_line(static_line[fd]);
	if (return_line == NULL)
	{
		gnl_free_char_pointer(&static_line[fd]);
		return (0);
	}	
	static_line[fd] = gnl_set_static_line(static_line[fd]);
	return (return_line);
}
