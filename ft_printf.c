/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:22:50 by kipark            #+#    #+#             */
/*   Updated: 2022/02/27 18:11:21 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	check_printf_plag(va_list va_ap, char str)
{
	int	write_byte;

	write_byte = 0;
	if (str == 'c')
		write_byte = ft_printf_format_c(va_ap);
	if (str == 'd')
		write_byte = ft_printf_format_d(va_ap);
	if (str == 'i')
		write_byte = ft_printf_format_i(va_ap);
	if (str == 'p')
		write_byte = ft_printf_format_p(va_ap);
	if (str == 's')
		write_byte = ft_printf_format_s(va_ap);
	if (str == 'u')
		write_byte = ft_printf_format_u(va_ap);
	if (str == 'x')
		write_byte = ft_printf_format_x(va_ap);
	if (str == 'X')
		write_byte = ft_printf_format_x_x(va_ap);
	if (str == '%')
		write_byte = write(1, "%", 1);
	if (write_byte == -1)
		write_byte = -1;
	return (write_byte);
}

int	printf_end(va_list *ap)
{
	va_end(*ap);
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printf_byte;
	int		before_printf_byte;

	before_printf_byte = 0;
	printf_byte = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		before_printf_byte = printf_byte;
		if (!check_printf_str_char(*str, '%'))
			printf_byte = printf_byte + write(1, str, 1);
		else
		{
			printf_byte = printf_byte + check_printf_plag(ap, *(str + 1));
			str++;
		}
		if (before_printf_byte > printf_byte)
			return (printf_end(&ap));
		str++;
	}
	return (printf_byte);
}
