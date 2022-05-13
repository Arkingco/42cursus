/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:47:34 by kipark            #+#    #+#             */
/*   Updated: 2022/05/13 15:48:25 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include<string.h>
#include<stdio.h>
void fprint_child(int count_pipe, char **cmd)
{
	fprintf(stderr, "child_pipe %d\n", count_pipe);
	for(int i=0; cmd[i] != NULL; ++i)
	{
		fprintf(stderr, "cmd [%d] : %s\n",i ,cmd[i]);
	}
}

void child_pipe(int pipe_fd[2], int infile_fd, char **cmd, int count_pipe, char *file_name)
{
	int out_fd;

	fprint_child(count_pipe, cmd);
	if(infile_fd != -1)
		dup2_and_close(infile_fd, STDIN_FILENO);
	else
		dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);	
	if (count_pipe == 2)
	{
		out_fd = open(file_name, O_RDWR | O_CREAT , 0644);
		fprintf(stderr, "out_fd : %d\n", out_fd);
		if (out_fd == -1)
			error_exit(OPEN_ERROR);
		if (dup2(out_fd, STDOUT_FILENO) == -1)
			error_exit(DUP2_ERROR);
		close(out_fd);
	}
	else
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			error_exit(DUP2_ERROR);
	close(pipe_fd[1]);
	if(execve(cmd[0], cmd, NULL) == -1)
		error_exit(EXECVE_ERROR);
	perror(NULL);
	exit(1);
}

void	parent_pipe(int count_pipe, char **argv, char **envp)
{
	int	pid;
	int	pipe_fd[2];
	int	infile_fd;
	int	status;
	pid_t wait_id;

	while(count_pipe <= 2)
	{
		infile_fd = set_infile_fd(&count_pipe, pipe_fd, argv[1]);
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
		wait_id = waitpid(pid, &status, 0);
	}
}

// 명령어 널처리 파일 널처리 해야함 파서 대충 완료
int main(int argc, char **argv, char **envp)
{
	int count_pipe;
	int	total_pipe;

	if(argc < 4)
		error_exit(ARGC_ERROR);
	count_pipe = 1;
	total_pipe = argc - NOT_PIPE_ARG_COUNT;
	parent_pipe(count_pipe, argv, envp);
}