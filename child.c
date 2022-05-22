/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:04:17 by kipark            #+#    #+#             */
/*   Updated: 2022/05/22 20:45:56 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_pipe_fd(int pipe_fd[4], t_pipe_info pipes)
{
	if (pipe_fd[3] == -1)
	{
		close_pipe_2(pipe_fd[0], pipe_fd[1]);
		print_warring(INFILE_NOT_FOUND, pipes.infile);
		exit(INFILE_NOT_FOUND_EXIT_FLAG);
	}
	if (dup2(pipe_fd[3], STDIN_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(pipe_fd[3]);
}

static void	redirect_file(int pipe_fd[4], t_pipe_info pipes)
{
	if (pipes.count_pipe == pipes.total_pipe)
		outfile_open(pipes.outfile);
	else
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			error_exit(DUP2_ERROR);
	close_pipe_2(pipe_fd[0], pipe_fd[1]);
}

static void	excute_cmd(char **cmd)
{
	if (access(cmd[0], X_OK) != 0)
	{
		print_warring(COMMAND_NOT_FOUND, cmd[0]);
		exit(COMMAND_NOT_FOUND_EXIT_FLAG);
	}
	if (execve(cmd[0], cmd, NULL) == -1)
		error_exit(EXECVE_ERROR);
}

void	child_process(int pipe_fd[4], char **cmd, t_pipe_info pipes)
{
	check_pipe_fd(pipe_fd, pipes);
	redirect_file(pipe_fd, pipes);
	excute_cmd(cmd);
	perror(NULL);
	exit(0);
}
