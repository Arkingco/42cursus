/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:11:49 by kipark            #+#    #+#             */
/*   Updated: 2022/04/29 22:10:18 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void set_t_map(void *mlx, t_map *map)
{
	map->item = mlx_xpm_file_to_image(mlx, "./images/item.xpm", &map->img_width, &map->img_height);
	map->exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &map->img_width, &map->img_height);
	map->floor = mlx_xpm_file_to_image(mlx, "./images/floor.xpm", &map->img_width, &map->img_height);
	map->player = mlx_xpm_file_to_image(mlx, "./images/player.xpm",&map->img_width, &map->img_height);
	map->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &map->img_width, &map->img_height);
}

void show_image(void *mlx, void *mlx_win, char **map)
{
	t_map	map_info;
	int		row;
	int		colum;

	set_t_map(mlx, &map_info);
	row = 0;
	while(row < get_row_length(map))
	{
		colum = 0;
		while(colum < get_colum_length(map[0]))
		{
			if (map[row][colum] == '0')
				mlx_put_image_to_window(mlx, mlx_win, map_info.floor, colum * PIXEL_SIZE, row * PIXEL_SIZE);
			else if (map[row][colum] == '1')
				mlx_put_image_to_window(mlx, mlx_win, map_info.wall, colum * PIXEL_SIZE, row * PIXEL_SIZE);		
			else if (map[row][colum] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, map_info.item, colum * PIXEL_SIZE, row * PIXEL_SIZE);
			else if (map[row][colum] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, map_info.exit, colum * PIXEL_SIZE, row * PIXEL_SIZE);
			else if (map[row][colum] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, map_info.player, colum * PIXEL_SIZE, row * PIXEL_SIZE);
			colum++;
		}
		row++;
	}
}

