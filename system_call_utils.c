/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_call_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:23:12 by kipark            #+#    #+#             */
/*   Updated: 2022/05/13 15:44:33 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void dup2_and_close(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		error_exit(DUP2_ERROR);
	close(fd1);
}

int open_infile_fd(char *file_name)
{
	int infile_fd;

	infile_fd = open(file_name, O_RDONLY, 0644);
	if (infile_fd == -1)
		print_warring("zsh: no such file or directory : ", file_name);
	return (infile_fd);
}

int	set_infile_fd(int *count_pipe, int pipe_fd[2], char *file_name)
{
	int infile_fd;

	if (*count_pipe == 1)
    {
		infile_fd = open_infile_fd(file_name);
	}
	else
		infile_fd = pipe_fd[0];
	return (infile_fd);
}