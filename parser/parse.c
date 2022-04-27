/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:57:05 by kipark            #+#    #+#             */
/*   Updated: 2022/04/27 21:14:48 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void set_parsed_str(char *parsed_str, char *head_str)
{
	int idx;

	idx = 0;
	while (head_str[idx] != '\0')
	{
		parsed_str[idx] = head_str[idx];
		idx++;
	}
}

static void	set_head_to_char(t_list *list_head, char **parsed_str)
{
	parsed_str = malloc(sizeof(char *) * get_list_head_row(list_head));
	if (parsed_str == NULL)
		print_error(1);
	while (list_head != NULL)
	{
		parsed_str = malloc(sizeof(char) * get_list_head_colum(list_head));
		if (parsed_str != NULL)
			print_error(1);
		set_parsed_str(parsed_str, list_head->str);
		list_head = list_head->next;
	}
}

static t_list	*set_parsing_head(t_list *list_head, char **argv)
{
	int		fd;
	int		str_plag;
	t_list	*new_node;

	fd = open(argv[1], O_RDONLY);
	str_plag = 1;
	while (str_plag)
	{
		new_node = malloc(sizeof(t_list) * 1);
		if (new_node == NULL)
			print_error(1);
		new_node->str = get_next_line(fd);
		new_node->next = NULL;
		if (new_node->str != NULL)
			str_plag = 1;
		list_head->next = new_node;
		list_head = list_head->next;
	}
	close(fd);
}

char	**parse(t_list *list_head, char **argv)
{
	char	**parsed_str;

	set_parsing_head(list_head, argv);
	set_head_to_char(list_head, parsed_str);
	if (parsed_str_error_check())
		print_error(1);
	return (parsed_str);
}