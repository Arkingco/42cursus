/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:56:33 by kipark            #+#    #+#             */
/*   Updated: 2022/04/08 17:17:24 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void print_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

void error_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}