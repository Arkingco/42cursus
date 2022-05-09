/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:12:59 by kipark            #+#    #+#             */
/*   Updated: 2022/05/09 11:02:14 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include<stdio.h>
void child_pipe(int pipe_fd[2], int infile_fd, char *file_path, char **cmd_argv)
{
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(infile_fd);
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(pipe_fd[1]);
	// access 함수 사용해서 file_path 가 존재 하는지 확인 해야함
	if(execve(file_path, cmd_argv, NULL) == -1)
		error_exit(EXECVE_ERROR);
	perror(NULL);
	exit(1);
}

void	redirect_outfile(int read_only_pipe, char *output_file)
{
	int	out_fd;

	out_fd = open(output_file, O_RDONLY | O_CREAT, 0644);
	if (dup2(read_only_pipe, STDOUT_FILENO) == -1)
		error_exit(DUP2_ERROR);
}

void	parent_pipe(int count_pipe, char **argv)
{
	int	pid;
	int	pipe_fd[2];
	int infile_fd;

	count_pipe = 0;
	infile_fd = open(argv[1], O_RDONLY | O_CREAT, 0644);
	if (infile_fd == -1)
		error_exit(OPEN_ERROR);
	if (pipe(pipe_fd) == -1)
		error_exit(PIPE_ERROR);
	while(count_pipe--)
	{
		pid = fork();
		// 만약에 제대로 fork 받지 못했을 경우
		if (pid == -1)
			error_exit(FORK_ERROR);
		// 자식 프로세스 일 때
		if(pid == 0)
			child_pipe();
		if(count_pipe != 1)
			infile_fd = pipe_fd[0];
	}
	close(pipe_fd[1]);
	// 프로세스 끝내기
	redirect_outfile(pipe_fd, argv[2]);
}

// 파서 만들기
int main(int argc, char **argv, char **envp)
{
	int count_pipe;

	if(argc < 4)
		error_exit(ARGC_ERROR);
	count_pipe = argv - NOT_PIPE_ARG_COUNT;
	parent_pipe(count_pipe, argv);
}