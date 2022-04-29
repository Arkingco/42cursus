/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:01:26 by kipark            #+#    #+#             */
/*   Updated: 2022/04/29 22:23:25 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	param_init(t_param *param, char **map, void *mlx, void *mlx_win)
{
	int row;
	int colum;

	param->map = map;
	param->mlx = mlx;
	param->mlx_win = mlx_win;
	row = 0;
	while(param->map[row] != NULL)
	{
		colum = 0;
		while(param->map[row][colum] != '\0')
		{
			if (param->map[row][colum] == 'P')
			{
				param->x = row;
				param->y = colum;
			}
			colum++;
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*str_head;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	t_param param;
	int		map_width;
	int		map_heidth;

	if (argc < 2)
		return (0);
	str_head = NULL;
	map = parse(&str_head, argv);
	map_width = get_row_length(map);
	map_heidth = get_colum_length(map[0]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map_heidth * PIXEL_SIZE, map_width * PIXEL_SIZE, "Hello world!");
	show_image(mlx, mlx_win, map);
	param_init(&param, map, mlx, mlx_win);
	mlx_hook(mlx_win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx);
}
