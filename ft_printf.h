/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:23:11 by kipark            #+#    #+#             */
/*   Updated: 2022/02/07 21:39:54 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>

# include"format/ft_printf_format.h"
# include"util/ft_printf_util.h"

struct flag_list {
	int	sharp;
	int	zero;
	int	space;
	int	plus;
	int	minus;
	int	dot;
}

int	ft_printf(const char *str, ...);

#endif