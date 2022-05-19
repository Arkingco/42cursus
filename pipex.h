/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:13:13 by kipark            #+#    #+#             */
/*   Updated: 2022/05/19 16:19:54 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"

#define NOT_PIPE_ARG_COUNT 3

#define ARGC_ERROR		1
#define DUP2_ERROR		2
#define PIPE_ERROR		3
#define OPEN_ERROR		4
#define FORK_ERROR		5
#define EXECVE_ERROR	6
#define ACCESS_ERROR	7

#define	PATH_POINTER	5

#define PIPE_SIZE		4

void	print_warring(char *str, char *file_name);
void	print_error(char *str);
void	error_exit(int flag);
void	wait_exit(int count_pipe, int error_flag);

char	**cmd_parse(char *cmd_str, char **envp);

// system_call_utils
int		set_infile_fd(int count_pipe, int pipe_fd, char *file_name);
void	dup2_and_close(int fd1, int fd2);
void	outfile_open(char *file_name);
void	close_pipe_2(int fd1, int fd2);

void	str_free(char **str);
# endif