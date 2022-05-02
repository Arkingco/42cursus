/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:01:26 by kipark            #+#    #+#             */
/*   Updated: 2022/05/02 17:32:07 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	param_init(t_param *param, char **map, void *mlx, void *mlx_win)
{	
	int	row;
	int	colum;

	param->map = map;
	param->mlx = mlx;
	param->mlx_win = mlx_win;
	row = 0;
	while (param->map[row] != NULL)
	{
		colum = 0;
		while (param->map[row][colum] != '\0')
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

static void	game_start(char **map)
{
	void	*mlx;
	void	*mlx_win;
	int		y_size;
	int		x_size;
	t_param	param;

	y_size = get_row_length(map);
	x_size = get_column_length(map[0]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x_size * PX, y_size * PX, "so_long");
	param_init(&param, map, mlx, mlx_win);
	map_init(mlx, &param.map_info);
	set_background(mlx, mlx_win);
	show_image(mlx, mlx_win, map, param.map_info);
	mlx_hook(mlx_win, EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_hook(mlx_win, X_EVENT_EXIT, 0, &exit_window, NULL);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	t_list	*str_head;
	char	**map;

	if (argc != 2)
		print_error_str(EXIT_ERROR_PLAG, "Error\nArguments not match\n");
	str_head = NULL;
	map = parse(&str_head, argv);
	game_start(map);
}
