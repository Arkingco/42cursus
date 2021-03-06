/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:13 by kipark            #+#    #+#             */
/*   Updated: 2022/02/28 16:38:57 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	printf_recursive_d(long int result)
{
	char	write_a;
	int		write_byte;

	write_byte = 0;
	if (result < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		write_byte = printf_recursive_d(result * -1);
		write_byte++;
	}
	else
	{
		if (result > 9)
		{
			write_byte = printf_recursive_d(result / 10);
			if (write_byte == -1)
				return (-1);
		}
		write_a = (result % 10) + '0';
		if (write(1, &write_a, 1) == -1)
			return (-1);
		write_byte++;
	}
	return (write_byte);
}

int	ft_printf_format_d(va_list ap)
{
	return (printf_recursive_d((long int)va_arg(ap, int)));
}
