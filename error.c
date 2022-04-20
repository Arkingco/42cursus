/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:56:33 by kipark            #+#    #+#             */
/*   Updated: 2022/04/20 21:34:39 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_error(int exit_flag)
{
	write(2, "Error\n", 6);
	exit(exit_flag);
}

void	error_exit(int exit_flag)
{
	write(2, "Error\n", 6);
	exit(exit_flag);
}
