/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:47:34 by kipark            #+#    #+#             */
/*   Updated: 2022/05/22 20:41:44 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parent_process( char **argv, char **envp, t_pipe_info pipes)
{
	int		pid;
	int		pipe_fd[4];
	int		status;
	char	**cmd;
	pid_t	wait_id;

	while (pipes.count_pipe <= pipes.total_pipe)
	{
		pipe_fd[3] = set_infile_fd(pipes.count_pipe, pipe_fd[0], argv[1]);
		if (pipe(pipe_fd) == -1)
			wait_exit(pipes.count_pipe - 1, PIPE_ERROR);
		pid = fork();
		if (pid == -1)
			wait_exit(pipes.count_pipe - 1, FORK_ERROR);
		if (pid == 0)
		{
			cmd = cmd_parse(argv[pipes.count_pipe + 1], envp);
			child_process(pipe_fd, cmd, pipes);
		}
		close_pipe_2(pipe_fd[3], pipe_fd[1]);
		pipes.count_pipe++;
	}
	close_pipe_2(pipe_fd[0], -1);
	while (pipes.count_pipe--)
		wait_id = waitpid(-1, &status, 0);
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe_info	pipes;
	int exit_status;

	if (argc <= 4)
		error_exit(ARGC_ERROR);
	pipes.count_pipe = 1;
	pipes.total_pipe = argc - NOT_PIPE_ARG_COUNT;
	pipes.infile = argv[INFILE_INDEX];
	pipes.outfile = argv[argc - 1];
	exit_status = parent_process(argv, envp, pipes);
	// return (exit_status);
	exit (42);
}
