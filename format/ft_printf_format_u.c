/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:13 by kipark            #+#    #+#             */
/*   Updated: 2022/01/24 18:41:18 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_format.h"

static int ft_printf_recursive_u(unsigned int result)
{
    char write_a;
    int write_byte;

    write_byte = 0;
   if(result > 9)
        write_byte = ft_printf_recursive_u(result / 10);
    write_a = (result % 10) + '0';
    if(write(1, &write_a, 1) == -1)
        return(write_byte);
    write_byte++;
    return (write_byte);
}

int ft_printf_format_u(va_list ap)
{
    return (ft_printf_recursive_u(va_arg(ap, unsigned int)));
}