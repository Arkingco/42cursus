/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:13 by kipark            #+#    #+#             */
/*   Updated: 2022/01/23 13:43:25 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_format.h"

int ft_printf_format_c(va_list ap)
{
    char ap_result;
    
    ap_result = va_arg(ap, int);
    write(1, &ap_result, 1);

    return (1);
}