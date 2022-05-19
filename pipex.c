/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:47:34 by kipark            #+#    #+#             */
/*   Updated: 2022/05/19 19:55:59 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child_pipe(int pipe_fd[4], char **cmd, int cnt_pipe, char *file_name, int total_pipe)
{
	if(pipe_fd[3] == -1)
	{
		close_pipe_2(pipe_fd[0], pipe_fd[1]);
		exit(1);
	}
	if (dup2(pipe_fd[3], STDIN_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(pipe_fd[3]);
	if (cnt_pipe == total_pipe)
		outfile_open(file_name);
	else
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			error_exit(DUP2_ERROR);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if(access(cmd[0], X_OK) != 0)
	{
		print_warring("command not found: ", cmd[0]);
	 	exit(1);
	}
	if(execve(cmd[0], cmd, NULL) == -1)
		error_exit(EXECVE_ERROR);
	perror(NULL);
	exit(1);
}

void	parent_pipe( char **argv, char **envp, int cnt_pipe, int total_pipe)
{
	int	pid;
	int	pipe_fd[4];
	pid_t wait_id;

	while(cnt_pipe <= total_pipe)
	{
		pipe_fd[3] = set_infile_fd(cnt_pipe, pipe_fd[0], argv[1]);
		if (pipe(pipe_fd) == -1)
			wait_exit(cnt_pipe - 1, PIPE_ERROR);
		pid = fork();
		if (pid == -1)
			wait_exit(cnt_pipe - 1, FORK_ERROR);
		if (pid == 0)
			child_pipe(pipe_fd, cmd_parse(argv[cnt_pipe + 1], envp), cnt_pipe, argv[cnt_pipe + 2], total_pipe);
		close_pipe_2(pipe_fd[3], pipe_fd[1]);
		cnt_pipe++;
	}
	close(pipe_fd[0]);
	while(cnt_pipe--)
		wait_id = waitpid(-1, NULL, 0);
}

int main(int argc, char **argv, char **envp)
{
	int cnt_pipe;
	int	total_pipe;

	if(argc < 4)
		error_exit(ARGC_ERROR);
	cnt_pipe = 1;
	total_pipe = argc - NOT_PIPE_ARG_COUNT;
	parent_pipe(argv, envp, cnt_pipe, total_pipe);
}