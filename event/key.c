/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:57:13 by kipark            #+#    #+#             */
/*   Updated: 2022/05/01 19:16:25 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_play_move(t_param *param, int x, int y)
{
	if (param->map[x][y] == '0')
		key_event_meet_floor_item(param, x, y);
	else if (param->map[x][y] == '1')
		return (0);
	else if (param->map[x][y] == 'C')
		key_event_meet_floor_item(param, x, y);
	else if (param->map[x][y] == 'E')
		key_event_meet_exit(param, x, y);
	return (1);
}

void	player_move_write(int move_count)
{
	char	write_a;

	if (move_count > 10)
		player_move_write(move_count / 10);
	write_a = move_count % 10 + '0';
	if (write(1, &write_a, 1) == -1)
		exit(1);
	
}

int			key_press(int keycode, t_param *param)
{	
	static int move_count;
	int	before_move_count;

	before_move_count = move_count;
	if (keycode == KEY_W)
		move_count += check_play_move(param, param->x - 1, param->y);
	else if (keycode == KEY_S)
		move_count += check_play_move(param, param->x + 1, param->y);
	else if (keycode == KEY_A)
		move_count += check_play_move(param, param->x, param->y - 1);
	else if (keycode == KEY_D)
		move_count += check_play_move(param, param->x, param->y + 1);
	else if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
	show_image(param->mlx, param->mlx_win, param->map);
	if(before_move_count == move_count)
		return (0);
	player_move_write(move_count);
	if (write(1, "\n", 1) == -1)
		exit(1);
	return (0);
}