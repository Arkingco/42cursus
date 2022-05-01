/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:31:52 by kipark            #+#    #+#             */
/*   Updated: 2022/05/01 16:15:06 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_str_row_length(char **parsed_str)
{
	int	length;

	length = 0;
	while (parsed_str[length] != NULL)
		length++;
	if (length >= 3)
		return (0);
	return (1);
}

#include<stdio.h>
static int	check_str_rectangle(char **parsed_str)
{
	int	before_colum_length;
	int	idx;

	before_colum_length = get_colum_length(parsed_str[0]);
	idx = 1;
	while (parsed_str[idx] != NULL)
	{
		printf("%s\n", parsed_str[idx]);
		if (before_colum_length != get_colum_length(parsed_str[idx]))
			return (1);
		idx++;
	}
	return (0);
}

#include <stdio.h>
static int	check_wall_surrounded(char **parse_str, int colum_length)
{
	int	top;
	int	mid;
	int	bottom;
	int	idx;

	top = 0;
	mid = 1;
	idx = 0;
	bottom = get_row_length(parse_str) - 1;
	while (parse_str[top][idx] != '\0' && parse_str[top][idx] != '1')
		idx++;
	idx = 0;
	while (mid < bottom - 1)
	{
		if (parse_str[mid][0] != '1' || parse_str[mid][colum_length - 1] != '1')
			return (1);
		mid++;
	}
	idx = 0;
	while (parse_str[bottom][idx] != '\0' && parse_str[bottom][idx] != '1')
		idx++;
	return (0);
}

static int	check_need_object(char **parse_str)
{
	t_object	object;

	set_object(&object);
	check_object_parsed(parse_str, &object);
	if (object.error == 1)
		return (1);
	if (object.exit < 1 || object.item < 1 || object.player < 1)
		return (1);
	return (0);
}

int	parsed_str_error_check(char **parsed_str)
{
	if(check_str_row_length(parsed_str))
		print_error_str(1, "ERROR : row_under_3");
	if(check_str_rectangle(parsed_str))
		print_error_str(1, "ERROR : not_rectangle");
	if(check_wall_surrounded(parsed_str, get_colum_length(parsed_str[0])))
		print_error_str(1, "ERROR : not_wal_surrounded");
	if(check_need_object(parsed_str))
		print_error_str(1, "ERROR : not_much_object");
	return (0);
}
