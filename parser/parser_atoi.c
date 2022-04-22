/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:50:14 by kipark            #+#    #+#             */
/*   Updated: 2022/04/22 20:27:30 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
	return (0);
}

long int	parse_atoi(const char *str)
{
	long int	temp;
	int			minus_flag;

	minus_flag = 0;
	temp = 0;
	if (*str == '-')
	{
		minus_flag++;
		str++;
	}
	if (*str == '+' && !minus_flag)
		str++;
	while (isdigit(*str))
	{
		temp = (temp * 10) + (*str - '0');
		if (!minus_flag && temp > INT32_MAX)
			error_exit(1);
		if (minus_flag && temp - 1 > INT32_MAX)
			error_exit(1);
		str++;
	}
	if (minus_flag)
		return (temp * -1);
	return (temp);
}
