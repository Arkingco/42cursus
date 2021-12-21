/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:14:40 by kipark            #+#    #+#             */
/*   Updated: 2021/12/21 15:57:41 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

#define BUFFER_SIZE 100

g_list *make_buffer_list(g_list *buffer_list)
{
	g_list *new_list;
	g_list *first_list;
	
	new_list = NULL;
	first_list = NULL;
	if(buffer_list == NULL)
	{
		new_list = malloc(sizeof(g_list) * 1);
		if(new_list == NULL)
			return (0);
		new_list->next = NULL;
		new_list->content = NULL;
		return (new_list);
	}
	first_list = buffer_list;
	while(buffer_list -> next != NULL)
		buffer_list = buffer_list->next;
	new_list = malloc(sizeof(g_list) * 1);
	if(new_list == 0)
		return (0);
	new_list->next = NULL;
	new_list->content = NULL;
	buffer_list->next = new_list;
	return (first_list);
}

void set_next_line(g_list *bf_list, char *buffer, int buffer_size)
{
	int i;

	i = 0;
	while(bf_list->next != NULL)
		bf_list = bf_list->next;
	bf_list->content = malloc(sizeof(char) * buffer_size + 1);
	while(i < buffer_size)
	{
		bf_list->content[i] = buffer[i];
		++i;
	}
	bf_list->content[i] = '\0';
	bf_list->next = malloc(sizeof(g_list) * 1);
	if(bf_list->next == NULL)
		return ;
	bf_list->next->content = NULL;
	bf_list->next->next = NULL;
}

char *malloc_next_line(g_list **bf_list, int list_size)
{
	g_list *list;
	char *line;
	int gl_idx;
	int i;

	list = *bf_list;
	line = malloc(sizeof(char) * (list_size + 10));
	if(line == 0)
		return (0);
	gl_idx = 0;
	i = 0;
	while(!list)
	{
		if(list->content[i] == '\0' && list->next == NULL)
			return (line);
		if(list->content[i] == '\0')
		{
			list = list->next;
			i = 0;
		}
		line[gl_idx] = list->content[i];
		gl_idx++;
		i++;
	}
	return (0);
}

void print_list(g_list *bf_list)
{
	printf("%s", bf_list->content);
	while(bf_list->next != NULL)
	{
		bf_list = bf_list->next;
		printf("%s", bf_list->content);
	}
	printf("\n");
}

char *get_next_linelist(int fd)
{
	static char	buffer[BUFFER_SIZE];
	g_list		*bf_list;
	char		*get_line;
	int			list_string_size;

	list_string_size = BUFFER_SIZE;
	bf_list = make_buffer_list(NULL);
	while ((read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (ft_strchr(buffer, '\n') != 0)
		{
			list_string_size += ft_strchr(buffer, '\n');
			set_next_line(bf_list, buffer, ft_strchr(buffer, '\n'));
			break;
		}
		print_list(bf_list);
		set_next_line(bf_list, buffer, BUFFER_SIZE);
		list_string_size += BUFFER_SIZE;
	}
	get_line = malloc_next_line(&bf_list, list_string_size);
	if(get_line == 0)
		return (0);
	printf("%s\n", get_line);
	return (0);
}

///
///		list로 만든 get_next_line
///


///
///		malloc 으로 만든 get_next_line
///

char *set_get_line_char(char *get_line, char *buffer, int buffer_length)
{
	char	*new_line;
	int	get_line_length;
	int i;

	i = 0;
	get_line_length = ft_strlen(get_line);
	new_line = malloc(sizeof(char) * (get_line_length + buffer_length + 1));
	if(new_line == NULL)
		return (0);
	while(i < get_line_length)
	{
		new_line[i] = get_line[i];
		++i;
	}
	while(i < buffer_length + get_line_length)
	{
		new_line[i] = buffer[i - get_line_length];
		++i;
	}
	new_line[i] = '\0';
	return (new_line);
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*get_line;

	get_line = "";
	while ((read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (ft_strchr(buffer, '\n') != 0)
		{
			get_line = set_get_line_char(get_line, buffer, ft_strchr(buffer, '\n'));
			break;
		}
		get_line = set_get_line_char(get_line, buffer, BUFFER_SIZE);
	}
	printf("%s", get_line);

	return (get_line);
}