/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtions_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:12:59 by kipark            #+#    #+#             */
/*   Updated: 2022/05/11 11:40:08 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void unlink_acess(char **argv)
{
	char *file_name = argv[1];
	int return_access = access(file_name, F_OK);
	printf("%s %d \n", argv[1], return_access);
	if (return_access == 0)
	{
		printf("파일이 있습니다.\n");
		if (!unlink(file_name))
		{
			printf("파일 unlink 완료");
		}
		else
		{
			printf("fail file unlink");
		}
		
	}
	else if (return_access == -1)
	{
		printf("파일이 없습니다");
	}
	else 
	{
		printf("정의 되지 않은 에러");
	}
}

int		global;
void run_fork()
{
	int		automatic;
	int 	*heap;
	pid_t	pid;

	global = 10;
	automatic = 10;
	heap = malloc(sizeof(int));
	if (!heap)
		return ;
	printf("where is the start location\n");
	pid = fork();
	if(pid == -1)
	{
		free(heap);
		return ;
	}
	else if(!pid)
	{
		printf("Child: Before operations -> %d (Global), %d (Automatic), %d (Heap)\n", global, automatic, *heap);
		global += 10;
		automatic += 10;
		*heap += 10;
		printf("Child: After operations -> %d (Global), %d (Automatic), %d (Heap)\n", global, automatic, *heap);
	}
	else if(pid)
	{
		printf("Parent: Before operations -> %d (Global), %d (Automatic), %d (Heap)\n", global, automatic, *heap);
		global += 20;
		automatic += 20;
		*heap += 20;
		printf("Parent: After operations -> %d (Global), %d (Automatic), %d (Heap)\n", global, automatic, *heap);
	}
	free(heap);
	printf("int call  %d \n", pid);
	return ;
}

int test_fork_usleep()
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("Child: I got a pid %d internally\n", pid);
		usleep(100000);
		printf("Child: Exiting with Code 0\n");
	}
	else if (pid)
	{
		printf("Parent: I have a Child which pid is %d\n", pid);
		printf("Parent: Exiting with Code 0\n");
	}
	return (0);
}

int fork_error()
{
	pid_t	pid;
	pid_t	ret;
	int		status;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("Child: I don't know how to be handled\n");
		usleep(10000000);
		return (3);
	}
	else
	{
		printf("Parent: I have a Child with pid %d\n", pid);
		ret = waitpid(pid, &status, WUNTRACED | WCONTINUED);
		printf("Parent: Successfully got status from %d Child\n", ret);
		if (WIFEXITED(status))
			printf("Parent: Exited!\vExit Code is %d, Signal is %d", WEXITSTATUS(status), WTERMSIG(status));
		else if (WIFSIGNALED(status))
			printf("Parent: Signaled!\vExit Code is %d, Signal is %d", WEXITSTATUS(status), WTERMSIG(status));
		else if (WIFSTOPPED(status))
			printf("Parent: Stopped!\vExit Code is %d, Signal is %d", WSTOPSIG(status), WTERMSIG(status));
		else if (WIFCONTINUED(status))
			printf("Parent: Continued!\vExit Code is %d, Signal is %d", WSTOPSIG(status), WTERMSIG(status));
	}
	return (0);
}

int zombie_child()
{
	pid_t	pid;
	pid_t	ret;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
		printf("Child: I will be exited\n");
	else
	{
		printf("Parent: I have a Child which pid is %d\n", pid);
		while (1)
			;
	}
	return (0);
}

int not_a_zombie_child()
{
	pid_t	pid;
	pid_t	ret;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
		printf("Child: I will be exited\n");
	else
	{
		printf("Parent: I have a Child which pid is %d\n", pid);
		ret = wait(NULL);
		printf("parent: %d child has been restieved \n", pid);
		while (1)
			;
	}
	return (0);
}

void handler(int sig)
{
	pid_t	ret;
	int		status;

	if (sig != SIGCHLD)
		exit(1);
	ret = waitpid(-1, &status, WNOHANG);
	printf("Parent: Successfully got status from %d Child\n", ret);
	printf("Parent: Exit Code is %d, Signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
	exit(0);
}

int	signal_handler()
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("Child: I am going to take a sleep for 5 seconds\n");
		usleep(5000000);
		return (0);
	}
	else
	{
		printf("Parent: I have a Child which pid is %d\n", pid);
		signal(SIGCHLD, handler);
		while(1)
			;
	}
	return (0);
}

void childcommand()
{
	int		ret;
	char	buffer[BUFFER_SIZE];

	ret = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
}

void childproc(int pipe[2])
{
	int		fd;
	int		r_fd;
	int		w_fd;

	printf("Child: i'm going to close fd for Read\n");
	printf("Child: i'm going to connect STDOUT to fd for Write\n");
	printf("Child: I'm going to connect STDIN to fd from a file\n");
	printf("Child: Eventually I'll read from STDIN (file) and write to STDOUT (pipe)\n");	
	close(pipe[P_READ]);
	w_fd = dup2(pipe[P_WRITE], STDOUT_FILENO);
	close(pipe[P_WRITE]);
	if (w_fd == -1)
		exit(1);
	fd = open("read.txt", O_RDONLY);
	if (fd == -1)
		exit(1);
	r_fd = dup2(fd, STDIN_FILENO);
	close(fd);
	if (r_fd == -1)
		exit(1);
	childcommand();
}

void parentcommand()
{
	int		ret;
	char	buffer[BUFFER_SIZE];
	
	ret = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
}

void parentproc(int pipe[2], pid_t pid)
{
	int		fd;
	int		r_fd;
	int		w_fd;
	
	printf("Parent: I'm going to close fd for Write\n");
	printf("Parent: I'm going to connect STDIN to fd for Read\n");
	printf("Parent: I'm goint to connect STDOUT to fd from a file \n");
	printf("Parent: Eventually I'll read from STDIN (pipe) and write to STDOUT (file)\n");
	close(pipe[P_WRITE]);
	r_fd = dup2(pipe[P_READ], STDIN_FILENO);
	close(pipe[P_READ]);
	if (r_fd == -1)
		exit(1);
	fd = open("write.txt", O_WRONLY);
	if (fd == -1)
		exit(1);
	w_fd = dup2(fd, STDOUT_FILENO);
	close(fd);
	if (w_fd == -1)
		exit(1);
	if (waitpid(pid, NULL, 0) == -1)
		exit(1);
	parentcommand();
}

void run_execve(int argc, char **argv)
{
	int		i;
	char	**args;

	if (argc == 1)
		return (1);
	i = -1;
	args = (char **)malloc(argc * sizeof(char *));
	if (!args)
		return (1);
	args[argc - 1] = NULL;
	while (++i < argc - 1)
		args[i] = argv[i + 1];
	execve("/bin/ls", args, NULL);
	free(args);
	return (0);
}


int main(int argc, char **argv)
{
	// if(argc < 1)
	// 	return (0);
	// unlink_acess(argv);

	// 	fork 테스트
	// run_fork();
	// printf("\nglobal is what\n");
	// test_fork_usleep();
	// fork_error();
	// not_a_zombie_child();
	// signal_handler();

	// int fd[2];
	// pid_t	pid;

	// if (pipe(fd) == -1)
	// 	return (1);
	// printf("Parent: fd for Read is %d, fd for Write is %d\n", fd[P_READ], fd[P_WRITE]);
	// pid = fork();
	// if (pid == -1)
	// {
	// 	close(fd[P_READ]);
	// 	close(fd[P_WRITE]);
	// 	return (1);
	// }
	// else if (!pid)
	// 	childproc(fd);
	// else
	// 	parentproc(fd, pid);


}
