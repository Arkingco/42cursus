/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:13 by kipark            #+#    #+#             */
/*   Updated: 2022/02/28 16:43:05 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf_format_c(va_list ap)
{
	unsigned char	ap_result;

	ap_result = (unsigned char)va_arg(ap, int);
	if (write(1, &ap_result, 1) == -1)
		return (-1);
	return (1);
}
