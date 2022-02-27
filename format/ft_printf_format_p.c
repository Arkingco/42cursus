/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:59:15 by kipark            #+#    #+#             */
/*   Updated: 2022/02/27 21:46:19 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_printf_recursive_p(size_t result)
{
	char	write_a;
	int		write_byte;

	write_byte = 0;
	if (result > 15)
	{
		write_byte = ft_printf_recursive_p(result / 16);
		if (write_byte == -1)
			return (-1);
	}
	write_a = util_char_10_to_16(result % 16);
	if (write(1, &write_a, 1) == -1)
		return (-1);
	write_byte++;
	return (write_byte);
}

static int	ft_printf_format_p_run(size_t add_to_size_t)
{
	int	print_byte;

	print_byte = 0;
	print_byte += util_format_write("0x");
	if (print_byte == -1)
		return (-1);
	print_byte += ft_printf_recursive_p(add_to_size_t);
	if (print_byte == -1)
		return (-1);
	return (print_byte);
}

int	ft_printf_format_p(va_list ap)
{
	return (ft_printf_format_p_run((size_t)va_arg(ap, void *)));
}
