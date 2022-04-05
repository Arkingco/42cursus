/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:32:28 by kipark            #+#    #+#             */
/*   Updated: 2022/04/05 16:45:22 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int paser_check_str_error(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			if(str[i] != '-' && str[i] != '+')
				return (1);
		if (str[i] == '-' ||str[i] == '+')
			if (i > 0 || str[i+1] == '\0')
				return (1);
		++i;
	}
	return (0);
}

int paser_error(char **need_parsed)
{
	int idx;

	idx = 0;
	if(*need_parsed == NULL)
		error_exit();
	while(need_parsed[idx] != NULL)
	{
		if(paser_check_str_error(need_parsed[idx]))
			error_exit();
		idx++;
	}
	return (0);
}