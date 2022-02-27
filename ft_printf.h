/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:23:11 by kipark            #+#    #+#             */
/*   Updated: 2022/02/27 18:12:29 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>

# include"format/ft_printf_format.h"
# include"util/ft_printf_util.h"

typedef struct s_flag_list {
	int	sharp;
	int	zero;
	int	space;
	int	plus;
	int	minus;
	int	dot;
}	t_flag_list;

typedef struct s_str_design {
	long long int	str_length;
	char			*print_str;
}	t_str_dedign;

int	ft_printf(const char *str, ...);

#endif