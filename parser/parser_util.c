/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:47:46 by kipark            #+#    #+#             */
/*   Updated: 2022/04/03 17:20:56 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	need_parse_length(char **input_argv)
{
	int i;

	i = 0;
	while(input_argv[i] != NULL)
		i++;
	return (i);
}