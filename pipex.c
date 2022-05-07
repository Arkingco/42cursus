/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:12:59 by kipark            #+#    #+#             */
/*   Updated: 2022/05/08 06:53:58 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include<stdio.h>

// 인자 값 들어가야함
int open_file()
{
	
}

void child_pipe(int fds[2], int infile_fd, char *file_path, char **cmd_argv)
{
	if(dup2(fds[1], STDIN_FILENO) == -1)
		print_error("dup2_error");
	close(fds[1]);
	close(fds[0]);
	if(dup2(infile_fd, STDOUT_FILENO) == -1)
		print_error("dup2_error");
	close(infile_fd);
	execve(file_path, cmd_argv, NULL);
	perror(NULL);
	exit(1);
}

void works()
{
	int	pid;
	int	fds[2];
	int infile_fd;

	infile_fd = open_file();
	pipe(fds);
	while(/* 파이프 수 만큼 while문 돌리기 */1)
	{
		pid = fork();
		// 만약에 제대로 fork 받지 못했을 경우
		if (pid == -1)
		{

		}
		// 자식 프로세스 일 때
		if(pid == 0)
		{
			child_pipe();
		}
		else
		{
			
		}
	}
}

int main(int argc, char **argv, char **envp) {
	for(int i=0; envp[i] != NULL; ++i)
	{
		printf("%s\n", envp[i]);
	}
}