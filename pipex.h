/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:13:13 by kipark            #+#    #+#             */
/*   Updated: 2022/05/09 15:26:09 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
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

void	print_error(char *str);
void	error_exit(int flag);
void    str_free(char **str, int index);

char	**cmd_parse(char *cmd_str, char **envp);

# endif