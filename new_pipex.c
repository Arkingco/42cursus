/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:47:34 by kipark            #+#    #+#             */
/*   Updated: 2022/05/12 16:06:32 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include<string.h>
#include<stdio.h>
void child_pipe(int pipe_fd[2], int infile_fd, char **cmd, int count_pipe)
{
	fprintf(stderr, "child %d\n", count_pipe);
	for(int i=0; cmd[i] != NULL; ++i)
	{
		fprintf(stderr, "cmd [%d] : %s\n",i ,cmd[i]);
	}
	char buffer[4000];
	read(infile_fd, buffer, 4000);
	fprintf(stderr, " ininin child :%d\n%s\n",count_pipe, buffer);
	fprintf(stderr, " ininin child end -------------------- \n");
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		error_exit(DUP2_ERROR);
	close(infile_fd);
	close(pipe_fd[0]);
	if (count_pipe == 2)
	{
		int out_fd;
		out_fd = open("outfe", O_RDWR | O_CREAT , 0644);
		fprintf(stderr, "out_fd [%d]\n",out_fd);
		if (dup2(out_fd, STDOUT_FILENO) == -1)
			error_exit(DUP2_ERROR);
		close(out_fd);
		close(pipe_fd[1]);
	}
	else
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			error_exit(DUP2_ERROR);
		close(pipe_fd[1]); // jaham
	}
	if(execve(cmd[0], cmd, NULL) == -1)
		error_exit(EXECVE_ERROR);
	perror(NULL);
	exit(1);
}

void	redirect_outfile(int pipe_fd[2], char *output_file)
{
	int	out_fd;

	out_fd = open(output_file, O_RDWR | O_CREAT , 0644);
	char buffer[4000];
	read(pipe_fd[0], buffer, 4000);
	write(out_fd, buffer, ft_strlen(buffer));
}

// 싹 갈아 엎자 ~
void	parent_pipe(int count_pipe, char **argv, char **envp)
{
	int	pid;
	int	pipe_fd[2];
	int	infile_fd;
	int	status;
	pid_t wait_id;

	while(count_pipe <= 2)
	{
		if (count_pipe == 1)
		{
			infile_fd = open(argv[1], O_RDWR | O_CREAT, 0644);
			if (infile_fd == -1)
				error_exit(OPEN_ERROR);
		}
		else
			infile_fd = pipe_fd[0];
		if (pipe(pipe_fd) == -1)
			error_exit(PIPE_ERROR);
		pid = fork();
		if (pid == -1)
			error_exit(FORK_ERROR);
		if (pid == 0)
			child_pipe(pipe_fd, infile_fd, cmd_parse(argv[count_pipe + 1], envp), count_pipe);
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