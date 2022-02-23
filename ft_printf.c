/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:22:50 by kipark            #+#    #+#             */
/*   Updated: 2022/02/23 20:40:46 by kipark           ###   ########seoul.kr  */
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
	int		check_printf_plag_byte;

	check_printf_plag_byte = 0;
	printf_byte = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (!check_printf_str_char(*str, '%'))
		{
			if (write(1, str, 1) == -1)
				return (-1);
			printf_byte++;
		}
		else
		{
			check_printf_plag_byte = check_printf_plag(ap, *(str + 1));
			if(check_printf_plag_byte == -1)
				return (-1);
			
			str++;
		}
		str++;
	}
	va_end(ap);
	return (printf_byte);
}
