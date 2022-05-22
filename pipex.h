/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:13:13 by kipark            #+#    #+#             */
/*   Updated: 2022/05/22 20:42:23 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "error.h"

# define INFILE_INDEX 1
# define NOT_PIPE_ARG_COUNT 3
# define PATH_POINTER	5

typedef struct s_pipe_info {
	int		count_pipe;
	int		total_pipe;
	char	*infile;
	char	*outfile;
}	t_pipe_info;

void	print_warring(char *str, char *file_name);
void	print_error(char *str);
void	error_exit(int flag);
void	wait_exit(int count_pipe, int error_flag);

char	**cmd_parse(char *cmd_str, char **envp);

int		set_infile_fd(int count_pipe, int pipe_fd, char *file_name);
void	dup2_and_close(int fd1, int fd2);
void	outfile_open(char *file_name);
void	close_pipe_2(int fd1, int fd2);
void	str_free(char **str);

void	child_process(int pipe_fd[4], char **cmd, t_pipe_info pipes);

#endif