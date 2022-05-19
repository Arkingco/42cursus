/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:58:29 by kipark            #+#    #+#             */
/*   Updated: 2022/05/19 16:30:12 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_exit(int count_pipe, int error_flag)
{
	int wait_process;

	while(count_pipe--)
		wait_process = waitpid(-1, NULL, 0);
	error_exit(error_flag);
}

void	error_exit(int flag)
{
	if (flag == DUP2_ERROR)
		print_error("Error : dup2 return -1\n");
	if (flag == OPEN_ERROR)
		print_error("Error : open return -1\n");
	if (flag == PIPE_ERROR)
		print_error("Error : pipe return -1\n");
	if (flag == FORK_ERROR)
		print_error("Error : fork return -1\n");
	if (flag == ARGC_ERROR)
		print_error("Error : not enough arg\n");
	if (flag == EXECVE_ERROR)
		print_error("Error : execve return -1\n");
	if (flag == ACCESS_ERROR)
		print_error("Error : access return -1 \n");
}

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	print_warring(char *str, char *file_name)
{
	write(2, str, ft_strlen(str));
	write(2, file_name, ft_strlen(file_name));
	write(2, "\n", 1);
}