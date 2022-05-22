/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_call_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:23:12 by kipark            #+#    #+#             */
/*   Updated: 2022/05/22 22:13:24 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe_2(int fd1, int fd2)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
	return ;
}

void	outfile_open(char *file_name)
{
	int	out_fd;

	out_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd == -1)
		error_exit(OPEN_ERROR);
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(out_fd);
}

void	dup2_and_close(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		error_exit(DUP2_ERROR);
	close(fd1);
}

static int	open_infile_fd(char *file_name)
{
	int	infile_fd;

	infile_fd = open(file_name, O_RDONLY, 0644);
	return (infile_fd);
}

int	set_infile_fd(int count_pipe, int pipe_fd, char *file_name)
{
	int	infile_fd;

	if (count_pipe == 1)
		infile_fd = open_infile_fd(file_name);
	else
		infile_fd = pipe_fd;
	return (infile_fd);
}
