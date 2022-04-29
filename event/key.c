/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:57:13 by kipark            #+#    #+#             */
/*   Updated: 2022/04/29 22:21:51 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_play_move(t_param *param, int x, int y)
{
	if (param->map[x][y] == '0')
	{
		param->map[param->x][param->y] = '0';
		param->map[x][y] = 'P';
	}
	else if (param->map[x][y] == '1')
		return ;
	else if (param->map[x][y] == 'C')
		return ;
	else if (param->map[x][y] == 'E')
		return ;
}

#include<stdio.h>
int		key_press(int keycode, t_param *param)
{	
	if (keycode == KEY_W)
		check_play_move(param, param->x, param->y + 1);
	else if (keycode == KEY_S)
		check_play_move(param, param->x, param->y - 1);
	else if (keycode == KEY_A)
		check_play_move(param, param->x - 1, param->y);
	else if (keycode == KEY_D)
		check_play_move(param, param->x + 1, param->y);
	else if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
	printf("x : %d,  y: %d \n", param->x, param->y);
	show_image(param->mlx, param->mlx_win, param->map);
	return (0);
}