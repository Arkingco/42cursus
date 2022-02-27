/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:32:27 by kipark            #+#    #+#             */
/*   Updated: 2022/02/27 21:49:26 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	util_str_char(char str, char target)
{
	if (str == target)
		return (1);
	return (0);
}

int	util_str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

char	util_char_10_to_16_x(int index)
{
	char	*a;

	a = "0123456789abcdef";
	return (a[index]);
}

char	util_char_10_to_16(int index)
{
	char	*a;

	a = "0123456789ABCDEF";
	return (a[index]);
}

int	util_format_write(char *str)
{
	int	print_byte;

	if (str == NULL)
		return (print_byte = write(1, "(null)", 6));
	print_byte = write(1, str, util_str_len(str));
	if (print_byte == -1)
		return (-1);
	return (print_byte);
}
