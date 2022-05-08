/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:12:59 by kipark            #+#    #+#             */
/*   Updated: 2022/05/08 19:49:40 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include<stdio.h>
void child_pipe(int pipe_fd[2], int infile_fd, char *file_path, char **cmd_argv)
{
	if (dup2(pipe_fd[1], STDIN_FILENO) == -1)
		print_error("Error : dup2 return -1");
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	if (dup2(infile_fd, STDOUT_FILENO) == -1)
		print_error("Error : dup2 return -1");
	close(infile_fd);
	execve(file_path, cmd_argv, NULL);
	perror(NULL);
	exit(1);
}

void	redirect_outfile(int read_only_pipe, char *output_file)
{
	int	out_fd;

	out_fd = open(output_file, O_RDONLY | O_CREAT, 0644);
	if (dup2(read_only_pipe, STDOUT_FILENO) == -1)
		print_error("Error : dup2 return -1");
}

void	parent_pipe(int count_pipe, char **argv)
{
	int	pid;
	int	pipe_fd[2];
	int infile_fd;

	count_pipe = 0;
	infile_fd = open(argv[1], O_RDONLY | O_CREAT, 0644);
	if (infile_fd == -1)
		print_error("Error : open return -1");
	if (pipe(pipe_fd) == -1)
		print_error("Error : pipe return -1");
	while(count_pipe--)
	{
		pid = fork();
		// 만약에 제대로 fork 받지 못했을 경우
		if (pid == -1)
			print_error("Error : fork return -1");
		// 자식 프로세스 일 때
		if(pid == 0)
			// child_pipe();
		if(count_pipe != 1)
			infile_fd = pipe_fd[0];
	}
	close(pipe_fd[1]);
	redirect_outfile(pipe_fd, argv[2]);
}

int main(int argc, char **argv, char **envp)
{
	int count_pipe;

	if(argc < 4)
		print_error("Error : not enough arg");
	count_pipe = argv - NOT_PIPE_ARG_COUNT;
	parent_pipe(count_pipe, argv);
}