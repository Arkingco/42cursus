/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:07:00 by kipark            #+#    #+#             */
/*   Updated: 2022/01/23 13:41:42 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FORMAT_H
# define FT_PRINTF_FORMAT_H

#include<stdarg.h>
#include<unistd.h>

int ft_printf_format_c(va_list ap);
int ft_printf_format_s(va_list ap);
int ft_printf_format_d(va_list ap);
int ft_printf_format_i(va_list ap);
int ft_printf_format_u(va_list ap);
int ft_printf_format_x(va_list ap);
int ft_printf_format_x_x(va_list ap);
int ft_printf_format_p(va_list ap);


#endif