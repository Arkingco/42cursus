/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_x_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:13 by kipark            #+#    #+#             */
/*   Updated: 2022/01/30 17:59:53 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_format.h"

static int	ft_printf_recursive_x_x(unsigned int result)
{
	char	write_a;
	int		write_byte;

	write_byte = 0;
	if (result > 15)
		write_byte = ft_printf_recursive_x_x(result / 16);
	write_a = get_printf_char_10_to_16_x(result % 16);
	if (write(1, &write_a, 1) == -1)
		return (write_byte);
	write_byte++;
	return (write_byte);
}

ssize_t	ft_printf_format_x_x(va_list ap)
{
	return (ft_printf_recursive_x_x(va_arg(ap, unsigned int)));
}
