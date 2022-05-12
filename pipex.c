/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:12:59 by kipark            #+#    #+#             */
/*   Updated: 2022/05/12 13:16:21 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include<string.h>
#include<stdio.h>
void child_pipe(int pipe_fd[2], int infile_fd, char **cmd)
{
	// char buffer[4000];
	// read(pipe_fd[0], buffer, 4000);
	fprintf(stderr, "%s", "hi");
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(infile_fd);
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(pipe_fd[1]);
	if(execve(cmd[0], cmd, NULL) == -1)
		error_exit(EXECVE_ERROR);
	perror(NULL);
	exit(1);
}

void	redirect_outfile(int pipe_fd[2], char *output_file)
{
	int	out_fd;

	out_fd = open(output_file, O_RDWR | O_CREAT, 0644);
	char buffer[4000];
	read(pipe_fd[0], buffer, 4000);
	write(out_fd, buffer, 400);
}

void	parent_pipe(int count_pipe, char **argv, char **envp)
{
	int	pid;
	int	pipe_fd[2];
	int	infile_fd;
	int	status;
	pid_t wait_id;

	if (pipe(pipe_fd) == -1)
		error_exit(PIPE_ERROR);
	while(count_pipe <= 2)
	{
		pid = fork();
		if (pid == -1)
			error_exit(FORK_ERROR);
		if (pid == 0)
		{
			if (count_pipe == 1)
			{
				infile_fd = open(argv[1], O_RDONLY | O_CREAT, 0644);
				if (infile_fd == -1)
					error_exit(OPEN_ERROR);
			}
			else
				infile_fd = pipe_fd[0];
			child_pipe(pipe_fd, infile_fd, cmd_parse(argv[count_pipe + 1], envp));
		}
		count_pipe++;
		wait_id = waitpid(pid, &status, WNOHANG);
	}
	redirect_outfile(pipe_fd, argv[count_pipe + 2]);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
}

// 파서 만들기
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