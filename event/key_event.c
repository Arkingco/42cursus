/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:08:39 by kipark            #+#    #+#             */
/*   Updated: 2022/05/02 10:22:45 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_event_meet_floor_item(t_param *param, int x, int y)
{
	param->map[param->x][param->y] = '0';
	param->map[x][y] = 'P';
	param->x = x;
	param->y = y;
}

void	key_event_meet_exit(t_param *param, int x, int y)
{
	int	row;
	int	colum;
	int	clear;

	clear = 1;
	row = 0;
	x = 0;
	y = 0;
	while (param->map[row] != NULL)
	{
		colum = 0;
		while (param->map[row][colum] != '\0')
		{
			if (param->map[row][colum] == 'C')
				clear = 0;
			colum++;
		}
		row++;
	}
	if (clear == 1)
		exit(0);
}
