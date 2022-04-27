/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:31:52 by kipark            #+#    #+#             */
/*   Updated: 2022/04/27 21:14:35 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_str_row_length(char **parsed_str)
{
	int	length;

	length = 0;
	while(parsed_str[length] != NULL)
		length++;
	if(length >= 3)
		return (0);
	return (1);
}

static int	check_str_rectangle(char **parsed_str)
{
	int	before_colum_length;
	int idx;

	before_colum_length = get_colum_length(parsed_str[0]);
	idx = 1;
	while(parsed_str[idx] != NULL)
	{
		if(before_colum_length != get_colum_length(parsed_str[idx]))
			return (1);
		idx++;
	}
	return (0);
}

static int	check_wall_surrounded(char **parse_str, int	colum_length)
{
	int	top;
	int	mid;
	int	bottom;
	int idx;

	top = 0;
	mid = 1;
	bottom = get_row_length(parse_str) - 1;
	idx = 0;
	while(parse_str[top][idx] != '\0' && parse_str[top][idx] != '1')
		idx++;
	idx = 0;
	while(parse_str[mid] != NULL)
	{
		if(parse_str[mid][0] != '1' || parse_str[mid][colum_length - 1] != '1')
			return (1);
		idx++;
	}
	idx = 0;
	while(parse_str[bottom][idx] != '\0' && parse_str[bottom][idx] != '1')
		idx++;
}

static int	check_need_object(char **parse_str)
{
	t_object object;
	int	row;
	int	colum;

	set_object(&object);
	check_object_parsed(parse_str, &object);
	if (object.error == 1 ||object.exit < 1 || object.item < 1 || object.player < 1)
		return (1);
	return (0);
}

void	parsed_str_error_check(char **parsed_str)
{
	// str 가로 개수 확인
	// str이 사각형 인지 확인
	// 맵이 1로 둘러싸여져 있는지 확인
	// 맵에 필요한 값이 하나씩 있는지 확인
	return (check_str_row_length(parsed_str) || \
			check_str_rectangle(parsed_str) || \	
			check_wall_surrounded(parsed_str, get_colum_length(parsed_str[0])) || \
			check_need_object(parsed_str));
}