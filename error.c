/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:58:52 by kipark            #+#    #+#             */
/*   Updated: 2022/04/28 19:55:52 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int exit_flag)
{
	write(2, "Error\n", 6);
	exit(exit_flag);
}

void	print_error_str(int exit_flag, char *str)
{
	write(2, str, get_colum_length(str));
	exit(exit_flag);
}