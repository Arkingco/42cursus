/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:22:50 by kipark            #+#    #+#             */
/*   Updated: 2022/02/14 21:44:44 by kipark           ###   ########seoul.kr  */
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
	return (write_byte);
}

int set_flag_minus(t_flag_list *flag, char *str)
{
	flag->plus = 1;
	str++;
	if(*str == '#')
		set_flag_sharp(&flag, str);
	else if(*str == ' ')
		set_flag_space(&flag, str);
	else if(*str == '.')
		set_flag_dot(&flag, str);
	else if(*str == '+')
		set_flag_plus(&flag, str);
	else if(*str == '.')
		set_flag_dot(&flag, str);
	else if(*str == '-')
		set_flag_minus(&flag, str);
	return (0);
}

int set_flag_sharp(t_flag_list *flag, char *str)
{
	flag->sharp = 1;
	str++;
	if(*str == '0')
		set_flag_zero(&flag, str);
	else if(*str == '.')
		set_flag_dot(&flag, str);
	else if(*str == '-')
		set_flag_minus(&flag, str);
	return (0);
}

int set_flag_plus(t_flag_list *flag, char *str)
{
	flag->plus = 1;
	str++;
	if(*str == '0')
		set_flag_zero(&flag, str);
	else if(*str == '.')
		set_flag_dot(&flag, str);
	else if(*str == '+')
		set_flag_plus(&flag, str);
	else if(*str == '.')
		set_flag_dot(&flag, str);
	else if(*str == '-')
		set_flag_minus(&flag, str);
	return (0);
}

int set_flag_dot(t_flag_list *flag, char *str)
{
	return (0);
}

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

int set_flag_zero(t_flag_list *flag, char *str)
{
	flag->zero = 1;
	str++;
	if(*str == '#')
		set_flag_sharp(&flag, str);
	else if(*str == '0')
		set_flag_zero(&flag, str);
	else if(*str == ' ')
		set_flag_space(&flag, str);
	else if(*str == '.')
		set_flag_dot(&flag, str);
	else if(*str == '+')
		set_flag_plus(&flag, str);
	return (0);
}

void ft_printf_check_string(va_list va_ap, char *str)
{
	t_flag_list flag;
	
	if(*str == '#')
		set_flag_sharp(&flag, str);
	else if(*str == '0')
		set_flag_zero(&flag, str);
	else if(*str == ' ')
		set_flag_space(&flag, str);
	else if(*str == '.')
		set_flag_dot6g_plus(&flag, str);
	else if(*str == '.')
		set_flag_dot(&flag, str);
	else if(*str == '-')
		set_flag_minus(&flag, str);
	check_printf_plag(va_ap, str);
	return ;
}

int check_printf_flags(va_list va_ap, char *str)
{
	ft_printf_check_string(va_ap, str);
	return (0);
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
				return (0);
			printf_byte++;
		}
		else
		{
			if (str[i + 1] != '\0')
				printf_byte += check_printf_flags(ap, str + (i + 1));
			++i;
		}
		++i;
	}
	return (printf_byte);
}

