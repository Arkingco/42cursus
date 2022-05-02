/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:58:52 by kipark            #+#    #+#             */
/*   Updated: 2022/05/02 17:13:12 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(void *not_use)
{
	(void)not_use;
	exit(0);
}

void	print_error(int exit_flag)
{
	write(WRITE_ERROR_FD, "Error\n", 6);
	exit(exit_flag);
}

void	print_error_str(int exit_flag, char *str)
{
	write(WRITE_ERROR_FD, str, get_column_length(str));
	exit(exit_flag);
}
