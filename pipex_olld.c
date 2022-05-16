/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:47:34 by kipark            #+#    #+#             */
/*   Updated: 2022/05/16 17:04:23 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>
void child_pipe(int infile_fd, char **cmd, int count_pipe, char *file_name)
{
	int pipe_fd[2];
	int	pid;
	int infile_fd;

	infile_fd = set_infile_fd(count_pipe, pipe_fd[0], file_name);
	if (pipe(pipe_fd) == -1)
			error_exit(PIPE_ERROR);	
	pid = fork();
	if (pid == -1)
		error_exit(FORK_ERROR);
	if (pid == 0)
	{
	}
	close(pipe_fd[1]);	
}

void	parent_pipe(char **argv, char **envp, int count_pipe, int total_pipe)
{
	int wait_pid;

	while(count_pipe <= total_pipe)
		child_pipe();
	while(total_pipe--)
		wait_pid = waitpid(-1, NULL, 0);
}

int main(int argc, char **argv, char **envp)
{
	int count_pipe;
	int	total_pipe;

	if(argc < 4)
		error_exit(ARGC_ERROR);
	count_pipe = 1;
	total_pipe = argc - NOT_PIPE_ARG_COUNT;
	parent_pipe(argv, envp, count_pipe, total_pipe);
}