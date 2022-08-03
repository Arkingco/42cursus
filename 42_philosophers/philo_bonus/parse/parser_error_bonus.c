/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:32:28 by kipark            #+#    #+#             */
/*   Updated: 2022/08/03 14:47:08 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static int	paser_check_str_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			if (str[i] != '-' && str[i] != '+')
				return (1);
		if (str[i] == '-' || str[i] == '+')
			if (i > 0 || str[i + 1] == '\0')
				return (1);
		++i;
	}
	return (0);
}

int	paser_error(char **need_parsed)
{
	int	i;

	i = 0;
	while (need_parsed[i] != NULL)
	{
		if (paser_check_str_error(need_parsed[i]))
			return (1);
		i++;
	}
	return (0);
}
