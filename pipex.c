/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:47:34 by kipark            #+#    #+#             */
/*   Updated: 2022/05/17 17:34:45 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>
void child_pipe(int pipe_fd[2], int infile_fd, char **cmd, int count_pipe, char *file_name, int total_pipe)
{
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(infile_fd);
	if (count_pipe == total_pipe)
		outfile_open(file_name);
	else
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			error_exit(DUP2_ERROR);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if(*cmd == NULL)
		exit(1);
	if(infile_fd == -1)
		exit(1);
	if(execve(cmd[0], cmd, NULL) == -1)
		error_exit(EXECVE_ERROR);
	perror(NULL);
	exit(1);
}

void	open_pipe(int *pipe_fd, int count_pipe)
{
	if (pipe_fd[0] != -1 && pipe_fd[1] != -1)
	{
		pipe_fd[2] = pipe_fd[0];
		pipe_fd[3] = pipe_fd[1];
	}
	if (pipe(pipe_fd) == -1)
		wait_exit(count_pipe - 1, PIPE_ERROR);
} 

void	close_pipe(int *pipe_fd)
{
	if (pipe_fd[2] != -1 && pipe_fd[3] != -1)
	{
		close(pipe_fd[2]);
		close(pipe_fd[3]);
		pipe_fd[2] = pipe_fd[0];
		pipe_fd[3] = pipe_fd[1];
	}
	else
		return ;
}

void	parent_pipe( char **argv, char **envp, int count_pipe, int total_pipe)
{
	int	pid;
	int	pipe_fd[4];
	int	infile_fd;
	pid_t wait_id;

	while(count_pipe <= total_pipe)
	{
		infile_fd = set_infile_fd(count_pipe, pipe_fd[0], argv[1]);
		if (pipe(pipe_fd) == -1)
			wait_exit(count_pipe - 1, PIPE_ERROR);
		pid = fork();
		if (pid == -1)
			wait_exit(count_pipe - 1, FORK_ERROR);
		if (pid == 0)
			child_pipe(pipe_fd, infile_fd, cmd_parse(argv[count_pipe + 1], envp), count_pipe, argv[count_pipe + 2], total_pipe);\
		close(infile_fd);
		close(pipe_fd[1]);
		count_pipe++;
	}
	close(pipe_fd[0]);
	while(count_pipe--)
		wait_id = waitpid(-1, NULL, 0);
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