/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:29:30 by kipark            #+#    #+#             */
/*   Updated: 2022/05/21 15:32:05 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define COMMAND_NOT_FOUND 	"command not found: "
# define INFILE_NOT_FOUND 	"no such file or directory: "
# define INFILE_NOT_FOUND_EXIT_FLAG 1
# define COMMAND_NOT_FOUND_EXIT_FLAG 1

# define ARGC_ERROR		1
# define DUP2_ERROR		2
# define PIPE_ERROR		3
# define OPEN_ERROR		4
# define FORK_ERROR		5
# define EXECVE_ERROR	6
# define ACCESS_ERROR	7

#endif