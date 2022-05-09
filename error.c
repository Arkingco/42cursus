/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:58:29 by kipark            #+#    #+#             */
/*   Updated: 2022/05/09 16:16:38 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t str_len(char *str)
{
	int length;

	length = 0;
	while(str[length] != '\0')
		length++;
	return (length);
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
	return ;
}

void	print_error(char *str)
{
	write(2, str, str_len(str));
	exit(1);
}