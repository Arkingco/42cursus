/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:13 by kipark            #+#    #+#             */
/*   Updated: 2022/01/24 18:30:39 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_format.h"

int ft_printf_format_s(va_list ap)
{
    return(ft_printf_format_write(va_arg(ap, char *)));
}