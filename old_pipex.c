/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:47:34 by kipark            #+#    #+#             */
/*   Updated: 2022/05/14 19:31:35 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>

void outfile_open(char *file_name)
{
	int out_fd;

	out_fd = open(file_name, O_RDWR | O_CREAT , 0644);
	if (out_fd == -1)
		error_exit(OPEN_ERROR);
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(out_fd);
}

void child_pipe(int pipe_fd[2], int infile_fd, char **cmd, int count_pipe, char *file_name)
{
	if(infile_fd == -1)
		exit(1);
	dup2_and_close(infile_fd, STDIN_FILENO);
	close(pipe_fd[0]);
	if (count_pipe == 2)
		outfile_open(file_name);
	else
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			error_exit(DUP2_ERROR);
	close(pipe_fd[1]);
	if(*cmd == NULL)
		exit(1);
	if(execve(cmd[0], cmd, NULL) == -1)
		error_exit(EXECVE_ERROR);
	exit(1);
}


void	parent_pipe(int count_pipe, char **argv, char **envp, int total_pipe)
{
	int	pid;
	int	pipe_fd[2];
	int	infile_fd;
	pid_t wait_id;

	while(count_pipe <= total_pipe)
	{
		infile_fd = set_infile_fd(count_pipe, pipe_fd[0], argv[1]);
		if (infile_fd == -1)
			count_pipe++;
		if (pipe(pipe_fd) == -1)
			error_exit(PIPE_ERROR);
		pid = fork();
		if (pid == -1)
			error_exit(FORK_ERROR);
		if (pid == 0)
			child_pipe(pipe_fd, infile_fd, cmd_parse(argv[count_pipe + 1], envp), count_pipe, argv[count_pipe + 2]);
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
	parent_pipe(count_pipe, argv, envp, total_pipe);
}