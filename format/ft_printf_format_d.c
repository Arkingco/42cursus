/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:13 by kipark            #+#    #+#             */
/*   Updated: 2022/02/23 17:19:34 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_format.h"

static int	printf_recursive_d(long int result)
{
	char	write_a;
	int		write_byte;

	write_byte = 0;
	if (result < 0)
	{
		if (write(1, "-", 1) == -1)
			return (write_byte);
		write_byte = printf_recursive_d(result * -1);
		write_byte++;
	}
	else
	{
		if (result > 9)
			write_byte = printf_recursive_d(result / 10);
		write_a = (result % 10) + '0';
		if (write(1, &write_a, 1) == -1)
			return (write_byte);
		write_byte++;
	}
	return (write_byte);
}

static int	printf_itoa(long int result)
{
	int	print_byte;

	print_byte = 0;
	print_byte = printf_recursive_d(result);
	return (print_byte);
}

ssize_t	ft_printf_format_d(va_list ap)
{
	int	result;

	result = va_arg(ap, int);
	return (printf_itoa(result));
}
