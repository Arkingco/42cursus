/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:57:19 by kipark            #+#    #+#             */
/*   Updated: 2022/05/01 15:18:56 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define PIXEL_SIZE				64

typedef struct s_param {
	int		x;
	int		y;
	char 	**map;
	void	*mlx;
	void	*mlx_win;
}				t_param;

typedef struct s_player {
	int	get_item;
}				t_player;

typedef struct s_map {
	void *wall;
	void *floor;
	void *item;
	void *exit;
	void *player;
	int	img_width;
	int img_height;
}				t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_list {
	struct s_list	*next;
	char			*str;
}	t_list;

typedef struct s_object {
	int	space;
	int	player;
	int	wall;
	int	item;
	int	exit;
	int	error;
}	t_object;

int		gnl_strchr(char *s, char word);
int		gnl_strlen(char *s);
char	*gnl_strjoin(char *static_line, char *buffer, int buffer_length);
void	gnl_free_char_pointer(char **pointer);

char	*get_next_line(int fd);

int		get_list_head_colum(char *head_str);
int		get_list_head_row(t_list *list_head);

void	print_error(int exit_flag);
void	print_error_str(int exit_flag, char *str);
void	set_parsed_str(char *parsed_str, char *head_str);

int		parsed_str_error_check(char **parsed_str);
int		get_colum_length(char *str);
int		get_row_length(char **str);
void	set_object(t_object *t_object);
void	check_object_parsed(char **parsed_str, t_object *object);
char	*so_long_strjoin(char *buffer);

char	**parse(t_list **str_head, char **argv);
void 	show_image(void *mlx, void *mlx_win, char **pared_map);

int		key_press(int keycode, t_param *param);
void	key_event_meet_floor_item(t_param *param, int x, int y);
void	key_event_meet_exit(t_param *param, int x, int y);

#endif
