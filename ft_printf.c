/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:22:50 by kipark            #+#    #+#             */
/*   Updated: 2022/01/21 21:52:09 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int check_printf_plag(va_list va_ap, char str)
{
    int write_byte;

    write_byte = 0;
    if(str == 'c')
        write_byte = ft_printf_format_c(va_ap);
    return (0);
}
 
int ft_printf(const char *str, ...)
{
    va_list ap;
    int printf_byte;
    int i;

    i = 0;
    va_start(ap, str);
    while(str[i] != '\0')
    {
        if(!check_printf_str_char(str[i], '%'))
            write(1, &str[i], 1);
        else
        {
            check_printf_plag(ap, str[i+1]);
            ++i;
        }
        ++i;
    }

    return (0);
}

int main()
{
    ft_printf("hi%c %c", 'b', 'g');
}