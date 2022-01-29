/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:23:11 by kipark            #+#    #+#             */
/*   Updated: 2022/01/24 21:03:50 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTIL_H
# define FT_PRINTF_UTIL_H

# include<stdarg.h>
# include<unistd.h>

size_t	check_printf_str_len(char *str);
int		check_printf_str_char(char str, char target);
int		ft_printf_format_write(char *str);
char	get_printf_char_10_to_16_x(int index);
char	get_printf_char_10_to_16(int index);

#endif