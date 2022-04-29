/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:54:19 by kipark            #+#    #+#             */
/*   Updated: 2022/04/29 14:17:00 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_colum_length(char *str)
{
	int	idx;

	idx = 0;
	if(str == NULL)
		return (0);
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

int	get_row_length(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx] != NULL)
		idx++;
	return (idx);
}

void	set_object(t_object *object)
{
	object->exit = 0;
	object->item = 0;
	object->player = 0;
	object->space = 0;
	object->wall = 0;
	object->error = 0;
}

void	check_object_parsed(char **parsed_str, t_object *object)
{
	int	row;
	int	colum;

	row = 0;
	colum = 0;
	while (parsed_str[row] != NULL)
	{
		colum = 0;
		while (parsed_str[row][colum] != '\0')
		{
			if (parsed_str[row][colum] == '0')
			object->space += 1;
			else if (parsed_str[row][colum] == '1')
				object->wall += 1;
			else if (parsed_str[row][colum] == 'C')
				object->item += 1;
			else if (parsed_str[row][colum] == 'E')
				object->exit += 1;
			else if (parsed_str[row][colum] == 'P')
				object->player += 1;
			else
				object->error = 1;
			colum++;
		}
		row++;
	}
}
