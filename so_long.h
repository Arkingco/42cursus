/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:57:19 by kipark            #+#    #+#             */
/*   Updated: 2022/04/27 21:34:55 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 8192
# endif

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
void	gnl_free_char_pointer(char **pointer);

char	*get_next_line(int fd);

int		get_list_head_colum(char *head_str);
int		get_list_head_row(t_list *list_head);

void	print_error(int exit_flag);

int		parsed_str_error_check(char **parsed_str);
int		get_colum_length(char *str);
int		get_row_length(char **str);
void	set_object(t_object *t_object);
void	check_object_parsed(char **parsed_str, t_object *object);

char	**parse(t_list *str_head, char **argv);
#endif
