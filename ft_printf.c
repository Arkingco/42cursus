/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:22:50 by kipark            #+#    #+#             */
/*   Updated: 2022/01/23 20:47:45 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

int check_printf_plag(va_list va_ap, char str)
{
    int write_byte;

    write_byte = 0;
    if(str == 'c')
        write_byte = ft_printf_format_c(va_ap);
    if(str == 'd')
        write_byte = ft_printf_format_d(va_ap);
    if(str == 'i')
        write_byte = ft_printf_format_i(va_ap);
    if(str == 'p')
        write_byte = ft_printf_format_p(va_ap);
    return (write_byte);
}
 
int ft_printf(const char *str, ...)
{
    va_list ap;
    int printf_byte;
    int i;

    i = 0;
    printf_byte = 0;
    va_start(ap, str);
    while(str[i] != '\0')
    {
        if(!check_printf_str_char(str[i], '%'))
        {
             write(1, &str[i], 1);
             printf_byte++;
        }
        else
        {
            printf_byte += check_printf_plag(ap, str[i+1]);
            ++i;
        }
        ++i;
    }
    return (printf_byte);
}

int main()
{
    printf("\n%d\n", ft_printf("hi%c %c, %d [%i]", 'b', 'g', 1322, -123455));
}