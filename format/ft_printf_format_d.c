/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:13 by kipark            #+#    #+#             */
/*   Updated: 2022/01/23 16:32:30 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_format.h"

static int printf_recursive_c(long int result)
{
    
}

static int printf_itoa(long int result)
{
    long int nbr;
    int print_byte;
    
    print_byte = 0;
    if(result < 0)
    {
        result = result * -1;
        write(1, "-1", 1);
        print_byte++;
    }
    printf_recursive_c(result);
}

int ft_printf_format_d(va_list ap)
{
    int result;
    
    result = va_arg(ap, int);
}