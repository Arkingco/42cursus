/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:50:14 by kipark            #+#    #+#             */
/*   Updated: 2022/04/05 15:22:43 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static long int	is_space(const char *str)
{
	if ((*str >= 9 && *str <= 13) || *str == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
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
	while (is_space(str))
		str++;
	if (*str == '-')
	{
		minus_flag++;
		str++;
	}
	if (*str == '+' && !minus_flag)
		str++;
	while (ft_isdigit(*str))
	{
		temp = temp * 10;
		temp = temp + (*str - '0');
		str++;
	}
	if (minus_flag)
		return (temp * -1);
	return (temp);
}