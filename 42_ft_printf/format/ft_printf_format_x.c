/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:13 by kipark            #+#    #+#             */
/*   Updated: 2022/02/28 16:52:07 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_printf_recursive_x(unsigned int result)
{
	char	write_a;
	int		write_byte;

	write_byte = 0;
	if (result > 15)
	{
		write_byte = ft_printf_recursive_x(result / 16);
		if (write_byte == -1)
			return (-1);
	}
	write_a = util_char_10_to_16(result % 16);
	if (write(1, &write_a, 1) == -1)
		return (-1);
	write_byte++;
	return (write_byte);
}

int	ft_printf_format_x(va_list ap)
{
	return (ft_printf_recursive_x((unsigned int)va_arg(ap, int)));
}
