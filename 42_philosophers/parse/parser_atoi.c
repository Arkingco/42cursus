/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:50:14 by kipark            #+#    #+#             */
/*   Updated: 2022/07/18 21:14:54 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

static int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long int	parse_atoi(const char *str)
{
	long int	temp;
	int			minus_flag;

	minus_flag = 0;
	temp = 0;
	if (*str == '-')
		
	if (*str == '+')
		str++;
	while (isdigit(*str))
	{
		temp = (temp * 10) + (*str - '0');
		if (temp > INT32_MAX)
			print_error(1);
		str++;
	}
	return (temp);
}
