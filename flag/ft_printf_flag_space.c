/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:13 by kipark            #+#    #+#             */
/*   Updated: 2022/02/14 16:56:17 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_format.h"

int set_flag_space(t_flag_list *flag, char *str)
{
	flag->space = 1;
	str++;
	if(*str == '0')
		set_flag_zero(&flag, str);
	else if(*str == ' ')
		set_flag_space(&flag, str);
	else if(*str == '.')
		set_flag_dot(&flag, str);
	else if(*str == '-')
		set_flag_minus(&flag, str);
	return (0);
}