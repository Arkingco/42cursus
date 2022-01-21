/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:23:11 by kipark            #+#    #+#             */
/*   Updated: 2022/01/21 21:45:48 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTIL_H
# define FT_PRINTF_UTIL_H

#include<stdarg.h>
#include<unistd.h>

int check_printf_str_char(char str, char target);

#endif