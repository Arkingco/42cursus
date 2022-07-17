/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:21:14 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:15:15 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	is_space(const char *str)
{
	if ((*str >= 9 && *str <= 13) || *str == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	temp;
	int	minus_flag;

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
