/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:57:05 by kipark            #+#    #+#             */
/*   Updated: 2022/05/02 17:10:26 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**set_head_to_char(t_list *list_head)
{
	char	**map;
	int		idx;

	map = malloc(sizeof(char *) * get_list_head_row(list_head) + 1);
	if (map == NULL)
		print_error(1);
	idx = 0;
	while (list_head != NULL)
	{
		map[idx] = malloc(sizeof(char) * get_list_head_colum(list_head->str));
		if (map == NULL)
			print_error(1);
		set_parsed_str(map[idx], list_head->str);
		list_head = list_head->next;
		idx++;
	}
	map[idx] = NULL;
	return (map);
}

static void	head_append_node(t_list **list_head, char *gnl_return_str)
{
	t_list	*new_node;
	t_list	*list;

	new_node = malloc(sizeof(t_list *) * 1);
	if (new_node == NULL)
		print_error(1);
	new_node->str = so_long_strjoin(gnl_return_str);
	new_node->next = NULL;
	if (*list_head == NULL)
		*list_head = new_node;
	else
	{
		list = *list_head;
		while (list->next != 0)
			list = list->next;
		list->next = new_node;
	}
}

static void	set_parsing_head(t_list **list_head, char **argv)
{
	int		fd;
	char	*gnl_return_str;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error_str(1, "Error\nfile_not_found\n");
	while (1)
	{
		gnl_return_str = get_next_line(fd);
		if (gnl_return_str == NULL)
			break ;
		head_append_node(list_head, gnl_return_str);
		free(gnl_return_str);
		gnl_return_str = NULL;
	}
	close(fd);
}

static void	check_ber_file(char *file_name)
{
	char	*ber_file;
	int		idx;
	int		file_length;
	int		ber_file_length;

	ber_file = ".ber";
	ber_file_length = get_column_length(ber_file);
	file_length = get_column_length(file_name);
	idx = file_length - ber_file_length;
	while (idx < file_length)
	{
		if (file_name[idx] != ber_file[(idx + ber_file_length) - file_length])
			print_error_str(1, "Error\nfile_is_not_.ber\n");
		idx++;
	}
}

char	**parse(t_list **list_head, char **argv)
{
	char	**map;

	map = NULL;
	check_ber_file(argv[1]);
	set_parsing_head(list_head, argv);
	map = set_head_to_char(*list_head);
	if (parsed_str_error_check(map))
		print_error(1);
	return (map);
}
