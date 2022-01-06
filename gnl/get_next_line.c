/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:14:40 by kipark            #+#    #+#             */
/*   Updated: 2022/01/06 20:17:36 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

#define BUFFER_SIZE 100

///
///		malloc 으로 만든 get_next_line
///

char *gnl_set_line(char *static_line, char *buffer, int fd)
{
	while ((read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (gnl_strchr(buffer, '\n') != 0)
		{
			static_line = gnl_strjoin(static_line, buffer, gnl_strchr(buffer, '\n'));
			break;
		}
		static_line = gnl_strjoin(static_line, buffer, BUFFER_SIZE);
	}
	printf("\n%s\n", static_line);

	return (static_line);
}

char *gnl_set_return_line(char *static_line, char *return_line)
{
	return_line = 
}

char *get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	static char		*static_line;
	char			*return_line;
	 
	if(fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if(static_line == NULL || static_line = "")
	{
		static_line = gnl_set_line(static_line, buffer, fd);
	}
	
	

	return (static_line);
}