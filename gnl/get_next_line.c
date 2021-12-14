/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:14:40 by kipark            #+#    #+#             */
/*   Updated: 2021/12/14 17:27:36 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

#define BUFFER_SIZE 2

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
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	g_list	*bf_list;
	char *get_line;
	int next_line_counter;
	int max_line_counter;
	
	max_line_counter = 0;
	next_line_counter = 0;
	bf_list = make_buffer_list(NULL);
	while((read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if((next_line_counter += ft_strchr(buffer, '\n')) == 0)
			break;
		set_next_line(bf_list, buffer, ft_strlen(buffer));
		printf("%s", buffer);
	}
	printf("\n");
	get_line = malloc(sizeof(int));
	return (0);
}