/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:23:11 by kipark            #+#    #+#             */
/*   Updated: 2022/02/13 21:59:14 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>

# include"format/ft_printf_format.h"
# include"util/ft_printf_util.h"

typedef struct FLAG_LIST {
	int	sharp;
	int	zero;
	int	space;
	int	plus;
	int	minus;
	int	dot;
} flag_list;

typedef struct STR_DESIGN {
	long long int str_length;
	char *print_str;
} str_dedign;

int	ft_printf(const char *str, ...);

#endif