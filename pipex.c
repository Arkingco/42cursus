/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:12:59 by kipark            #+#    #+#             */
/*   Updated: 2022/05/10 12:25:53 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include<stdio.h>
void child_pipe(int pipe_fd[2], int infile_fd, char **cmd)
{
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(infile_fd);
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(pipe_fd[1]);
	// for(int i=0; cmd[i] != NULL; ++i)
	// 	fprintf(stderr, "child : %s\n", cmd[i]);
	if(execve(cmd[0], cmd, NULL) == -1)
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

void	parent_pipe(int count_pipe, int total_pipe, char **argv, char **envp)
{
	int	pid;
	int	pipe_fd[2];
	int infile_fd;

	infile_fd = open(argv[1], O_RDONLY | O_CREAT, 0644);
	if (infile_fd == -1)
		error_exit(OPEN_ERROR);
	if (pipe(pipe_fd) == -1)
		error_exit(PIPE_ERROR);
	while(count_pipe <= total_pipe)
	{
		pid = fork();
		if (pid == -1)
			error_exit(FORK_ERROR);
		if(pid == 0)
			child_pipe(pipe_fd, infile_fd, cmd_parse(argv[count_pipe + 1], envp));
		if(count_pipe != total_pipe)
			infile_fd = pipe_fd[0];
		count_pipe++;
	}
	close(pipe_fd[1]);
	char buffer[4000];
	read(pipe_fd[0], buffer, 4000);
	printf("%s", buffer);
	// 프로세스 끝내기
	// redirect_outfile(pipe_fd, argv[2]);
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
	parent_pipe(count_pipe, total_pipe, argv, envp);
}