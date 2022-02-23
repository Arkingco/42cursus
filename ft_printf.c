/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:22:50 by kipark            #+#    #+#             */
/*   Updated: 2022/02/23 17:27:37 by kipark           ###   ########seoul.kr  */
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
		return (-1);
	return (write_byte);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printf_byte;
	int		i;

	i = 0;
	printf_byte = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (!check_printf_str_char(str[i], '%'))
		{
			if (write(1, &str[i], 1) == -1)
				return (-1);
			printf_byte++;
		}
		else
		{
			if (str[i + 1] != '\0')
				if(check_printf_plag(ap, str[i+1]) == -1)
					return (-1);
				else
					printf_byte += check_printf_plag(ap, str[i++]);
		}
		++i;
	}
	va_end(ap);
	return (printf_byte);
}
