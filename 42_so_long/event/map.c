/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:11:49 by kipark            #+#    #+#             */
/*   Updated: 2022/05/02 17:12:08 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_init(void *mlx, t_map *map)
{
	int	img_w;
	int	img_h;

	map->y = 0;
	map->x = 0;
	map->i = mlx_xpm_file_to_image(mlx, "./img/i.xpm", &img_w, &img_h);
	map->e = mlx_xpm_file_to_image(mlx, "./img/e.xpm", &img_w, &img_h);
	map->f = mlx_xpm_file_to_image(mlx, "./img/f.xpm", &img_w, &img_h);
	map->p = mlx_xpm_file_to_image(mlx, "./img/p.xpm", &img_w, &img_h);
	map->w = mlx_xpm_file_to_image(mlx, "./img/w.xpm", &img_w, &img_h);
}

static void	put_image(void *mlx, void *win, t_map in, char object)
{
	if (object == '0')
		mlx_put_image_to_window(mlx, win, in.f, in.x * PX, in.y * PX);
	else if (object == '1')
		mlx_put_image_to_window(mlx, win, in.w, in.x * PX, in.y * PX);
	else if (object == 'C')
	{
		mlx_put_image_to_window(mlx, win, in.f, in.x * PX, in.y * PX);
		mlx_put_image_to_window(mlx, win, in.i, in.x * PX, in.y * PX);
	}
	else if (object == 'E')
		mlx_put_image_to_window(mlx, win, in.e, in.x * PX, in.y * PX);
	else if (object == 'P')
	{
		mlx_put_image_to_window(mlx, win, in.f, in.x * PX, in.y * PX);
		mlx_put_image_to_window(mlx, win, in.p, in.x * PX + 8, in.y * PX + 8);
	}
}

void	show_image(void *mlx, void *win, char **map, t_map in)
{
	while (map[in.y] != NULL)
	{
		in.x = 0;
		while (map[in.y][in.x] != '\0')
		{
			put_image(mlx, win, in, map[in.y][in.x]);
			in.x += 1;
		}
		in.y += 1;
	}
}

void	set_background(void *mlx, void *win)
{
	void	*background;
	int		img_w;
	int		img_h;

	background = mlx_xpm_file_to_image(mlx, "./img/b.xpm", &img_w, &img_h);
	mlx_put_image_to_window(mlx, win, background, 0, 0);
}
