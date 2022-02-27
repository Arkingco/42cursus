/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:23:11 by kipark            #+#    #+#             */
/*   Updated: 2022/02/27 21:57:23 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HEXADECIMAL_MAX_LEN 16

int		util_str_len(char *str);
int		util_str_char(char str, char target);
int		util_format_write(char *str);
char	util_char_10_to_16_x(int index);
char	util_char_10_to_16(int index);

int	ft_printf_format_c(va_list ap);
int	ft_printf_format_s(va_list ap);
int	ft_printf_format_d(va_list ap);
int	ft_printf_format_i(va_list ap);
int	ft_printf_format_u(va_list ap);
int	ft_printf_format_x(va_list ap);
int	ft_printf_format_x_x(va_list ap);
int	ft_printf_format_p(va_list ap);

int	ft_printf(const char *str, ...);

#endif